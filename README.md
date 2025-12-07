# LeetCode Practice (C++17 + GoogleTest)

A batteries-included workspace for grinding LeetCode problems in modern C++ while keeping the edit/compile/test loop fast. Every solution ships with focused unit tests so you can iterate with confidence.

## Project goals

- **Stay consistent** – identical folder structure, headers, and tests for every problem so you never lose time on boilerplate.
- **Favor performance** – default compiler warnings are cranked up (`-Wall -Wextra`) and solutions are written with time/space complexity front of mind.
- **Tight feedback loop** – GoogleTest runs via CTest and `compile_commands.json` enables clangd, clang-tidy, and other tooling.

## Directory layout

```
├── CMakeLists.txt            # Top-level build + testing orchestration
├── cmake/                    # Helper modules (submodule updater, etc.)
├── external/googletest/      # Vendored GoogleTest submodule
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
| Git             | Manages submodules (GoogleTest).                 |

## Getting started

### 1. Clone and Configure
The project automatically handles the GoogleTest submodule update during the first build.

```bash
git clone --recursive git@github.com:<you>/leetcode.git
cd leetcode

# Create build directory
mkdir build && cd build

# Configure the project
cmake ..
```

### 2. Build and Test
You can use standard CMake commands to build and run tests.

```bash
# Build everything (automatically uses all CPU cores if configured)
cmake --build . --parallel

# Run all tests
ctest --output-on-failure
```

### 3. Run Specific Tests
To focus on a single problem without running the entire suite, use the `-R` (Regex) flag with `ctest`:

```bash
# Run all tests for Two Sum
ctest -R two_sum

# Run all tests for the "Arrays" topic
ctest -R arrays
```

## Adding a new problem

The build system is **automated**. You do not need to edit `CMakeLists.txt` when adding new problems within existing topics.

1. **Create the Source File**
   Create `src/<topic>/my_problem.cpp` (and `.h` if desired).

2. **Create the Test File**
   Create `tests/<topic>/my_problem_test.cpp`.
   *Note: The test file MUST end in `_test.cpp` to be detected.*

3. **Build**
   Run `cmake ..` (or just rebuild) to let CMake detect the new files.

4. **New Topics**
   If you add a new folder (e.g. `src/graphs` and `tests/graphs`), you only need to add one line to the root `CMakeLists.txt`:
   ```cmake
   register_topic_tests(graphs)
   ```

## Tooling, clangd, and formatting

- The repo-level `.clang-format` defines the canonical style.
- `compile_commands.json` is automatically generated in `build/`, enabling full LSP support in Neovim/VSCode.
- Recommended clangd flags:
  ```bash
  clangd --background-index --clang-tidy --header-insertion=iwyu
  ```

## FAQ / Troubleshooting

- **Tests fail to build because Googletest isn’t found** – re-run `git submodule update --init --recursive`.
- **"Test executable not found"** – Ensure your test file ends in `_test.cpp` and re-run `cmake ..`.
- **clangd can’t find headers** – Ensure `build/compile_commands.json` exists.

Ship fast, keep the red-green-refactor loop tight, and always profile the slow solutions before committing to fancy optimizations. Happy grinding!
