# Tasktracker
![Tests](https://github.com/masonlet/tasktracker/actions/workflows/test.yml/badge.svg)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/std/the-standard)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)

Lightweight Windows 10/11 tool to manage folder statuses from the right-click context menu.     
Quickly mark folders as Finished, Hidden, Unfinished, or reset to Default.

⚠️ Icon changes may not appear immediately due to Windows icon cache.

## Features
- Add or remove task status options from the right-click menu
- Simple install/uninstall using a single installer
- Instantly mark folder icons with one of four states: 
  - **📁 Default** 
  - **✅ Finished**
  - **🚫 Hidden** 
  - **❌ Unfinished**

## Preview
### Context Menu
Right-click any folder to see Tasktracker options.    
![Context Menu](./images/menu.png)

### Folder Tracking Example
Folder icons reflect their current status.     
![Example](./images/example.png)

<br/>

## Prerequisites
- Windows 10 or 11
- Administrator privileges (required for context menu installation)

## Installation
1. Download the latest installer from [Releases](https://github.com/masonlet/tasktracker/releases)
2. Run the installer
3. To uninstall, simply re-run the installer

<br/>

## Building the Project
### Prerequisites
- C++17
- CMake 3.10+

### Build Steps
```bash
# 1. Clone the repository
git clone https://github.com/masonlet/tasktracker.git
cd tasktracker

# 2. Create a build directory and generate build files
cmake -B build

# 3. Build the project
cmake --build build
```
Or open the generated `.sln` file in Visual Studio and build the solution.

### Running Tests
```bash
cmake -B build -DBUILD_TESTS=ON
cmake --build build
ctest --test-dir build/shared
```

## License
MIT License — see [LICENSE](./LICENSE) for details.
