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
├── scripts/                  # Helper scripts for fast workflow
│   ├── build.sh              # Compiles the project
│   ├── test.sh               # Runs all tests
│   └── quick_test.sh         # Runs specific tests
├── src/                      # Implementation files
│   ├── arrays/               # Grouped by topic
│   │   ├── two_sum.cpp/.h
│   │   └── best_time_to_buy_stock.cpp/.h
│   └── lists/
│       └── queue.h           # Template classes in headers
├── tests/                    # 1:1 GoogleTest specs for each implementation
│   ├── arrays/
│   │   ├── two_sum_test.cpp
│   │   └── best_time_to_buy_stock_test.cpp
│   └── lists/
│       └── queue_test.cpp
└── .clang-format             # Repository-wide formatting contract
```

## Prerequisites

| Tool            | Why you need it                                  |
|-----------------|--------------------------------------------------|
| CMake ≥ 3.14    | Generates the build system + `compile_commands`. |
| clang++/GCC     | Compiles the C++17 sources.                      |
| Python 3        | Required by some GoogleTest helper scripts.      |

## Getting started

### 1. Build and Run All Tests
The easiest way to get started is using the helper scripts:

```bash
# Build everything (automatically uses all CPU cores)
./scripts/build.sh

# Build and run all tests
./scripts/test.sh
```

### 2. Run Specific Tests
To focus on a single problem without running the entire suite:

```bash
# Usage: ./scripts/quick_test.sh <problem_name> [filter]

# Run all tests for Two Sum
./scripts/quick_test.sh two_sum

# Run only the "BasicExample" test case for Two Sum
./scripts/quick_test.sh two_sum "BasicExample"
```

## Adding a new problem

The build system is **automated**. You do not need to edit `CMakeLists.txt` when adding new problems within existing topics.

1. **Create the Source File**
   Create `src/<topic>/my_problem.cpp` (and `.h` if desired).

2. **Create the Test File**
   Create `tests/<topic>/my_problem_test.cpp`.
   *Note: The test file MUST end in `_test.cpp` to be detected.*

3. **Build**
   Run `./scripts/build.sh`. CMake will automatically detect the new files, link them, and register the tests.

4. **New Topics**
   If you add a new folder (e.g. `src/graphs` and `tests/graphs`), you only need to add one line to the root `CMakeLists.txt`:
   ```cmake
   register_topic_tests(graphs)
   ```

## Tooling, clangd, and formatting

- The repo-level `.clang-format` defines the canonical style (Google style with adjustments).
- `compile_commands.json` is automatically generated in `build/`, enabling full LSP support in Neovim/VSCode.
- Recommended clangd flags:
  ```bash
  clangd --background-index --clang-tidy --header-insertion=iwyu
  ```

## FAQ / Troubleshooting

- **Tests fail to build because Googletest isn’t found** – re-run `git submodule update --init --recursive`.
- **"Test executable not found"** – Ensure your test file ends in `_test.cpp` and run `./scripts/build.sh` to refresh CMake.
- **clangd can’t find headers** – Ensure `build/compile_commands.json` exists.

Ship fast, keep the red-green-refactor loop tight, and always profile the slow solutions before committing to fancy optimizations. Happy grinding!
