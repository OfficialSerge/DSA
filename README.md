# LeetCode Practice (C++17 + GoogleTest)

A batteries-included workspace for grinding LeetCode problems in modern C++ while keeping the edit/compile/test loop fast. Every solution ships with focused unit tests so you can iterate with confidence and benchmark different approaches over time.

## Project goals

- **Stay consistent** – identical folder structure, headers, and tests for every problem so you never lose time on boilerplate.
- **Favor performance** – default compiler warnings are cranked up (`-Wall -Wextra`) and solutions are written with time/space complexity front of mind.
- **Tight feedback loop** – GoogleTest runs via CTest and `compile_commands.json` enables clangd, clang-tidy, and other tooling.

## Directory layout

```
├── CMakeLists.txt            # Top-level build + testing orchestration
├── cmake/                    # Helper modules (submodule updater, etc.)
├── external/googletest/      # Vendored GoogleTest submodule
├── src/arrays/               # Source files grouped by topic (arrays, dp, graph, ...)
│   ├── two_sum.cpp/.h
│   └── best_time_to_buy_stock.cpp/.h
├── tests/arrays/             # 1:1 GoogleTest specs for each implementation
│   ├── two_sum_test.cpp
│   └── best_time_to_buy_stock_test.cpp
└── .clang-format             # Repository-wide formatting contract
```

## Prerequisites

| Tool            | Why you need it                                  |
|-----------------|--------------------------------------------------|
| CMake ≥ 3.14    | Generates the build system + `compile_commands`. |
| clang++/AppleClang 14+ or GCC 11+ | Compiles the C++17 sources.       |
| Ninja or Make   | (Optional) Faster incremental builds.            |
| Python 3        | Required by some GoogleTest helper scripts.      |
| Xcode CLT (macOS)| Provides the `clangd`/`clang-format` binaries.   |

> **macOS tip:** Run `xcode-select --install` to pick up the command-line tools, then `xcrun --find clang-format` to locate Apple’s bundled formatter.

## Getting started

```bash
# Clone the repo and pull the GoogleTest submodule
git clone --recursive git@github.com:<you>/leetcode.git
cd leetcode
# (If you forgot --recursive)
git submodule update --init --recursive

# Configure + build (Ninja generator shown, use Unix Makefiles if you prefer)
cmake -S . -B build -G Ninja
cmake --build build

# Run the full test suite
ctest --test-dir build --output-on-failure
```

`CMAKE_EXPORT_COMPILE_COMMANDS` is already enabled, so `build/compile_commands.json` will appear after the first configure. Point clangd/other tooling at that file.

## Adding a new problem

1. Create the header + implementation under `src/<topic>/`. Follow the naming convention (`problem_name.h/.cpp`).
2. Add a GoogleTest spec in `tests/<topic>/problem_name_test.cpp`. The `tests/<topic>/CMakeLists.txt` automatically matches `*_test.cpp` files with the corresponding implementation.
3. Reconfigure if you added a brand-new topic directory: update `CMakeLists.txt` to `add_subdirectory(tests/<topic>)`.
4. Rebuild + run `ctest`. Failing tests should guide any edge cases you missed.

## Tooling, clangd, and formatting

- The repo-level `.clang-format` defines the canonical style (LLVM-based with a 100-column limit). Generate a fresh config with:
  ```bash
  $(xcrun --find clang-format) --style=llvm --dump-config > .clang-format
  ```
  Then tweak the options you care about (pointer alignment, column width, etc.).
- Recommended clangd command (Set via `nvim-lspconfig` or your editor):
  ```bash
  clangd \
    --background-index \
    --clang-tidy \
    --header-insertion=iwyu \
    --completion-style=detailed \
    --function-arg-placeholders \
    --style=file \
    --fallback-style=none
  ```
  `--style=file` ensures clangd respects `.clang-format`; `--fallback-style=none` makes missing configs obvious instead of silently reverting to LLVM/Google defaults.
- Format a file on demand with `:ClangFormat` (Neovim) or directly:
  ```bash
  $(xcrun --find clang-format) -i src/arrays/two_sum.cpp
  ```

## FAQ / Troubleshooting

- **Tests fail to build because Googletest isn’t found** – re-run `git submodule update --init --recursive` or delete `external/googletest` and re-pull.
- **clangd can’t find headers** – ensure Neovim points `clangd` at `build/compile_commands.json` (or symlink it to the repo root) and rebuild after adding new files.
- **Need to support another language/topic** – mirror the `src/arrays` + `tests/arrays` structure for DP, graphs, etc., then add the new test folder to the root `CMakeLists.txt`.

Ship fast, keep the red-green-refactor loop tight, and always profile the slow solutions before committing to fancy optimizations. Happy grinding!
