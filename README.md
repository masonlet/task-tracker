# Tasktracker

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

## Prerequisites
- Windows 10 or 11
- Administrator privileges (required for context menu installation)

## Installation
1. Download the latest installer from [Releases](https://github.com/masonlet/tasktracker/releases)
2. Run the installer
3. To uninstall, simply re-run the installer

## Building the Project
To build TaskTracker and Installer from source using CMake:

### 1. Clone the Repository
```bash
git clone https://github.com/masonlet/tasktracker.git
cd tasktracker
```

### 2. Create a Build Directory and Generate Build Files
```bash
mkdir build
cd build 
cmake ..
```

### 3. Build the Project
```bash
cmake --build .
```
Or open the generated `.sln` file in Visual Studio and build the solution.

## License
MIT License — see [LICENSE](./LICENSE) for details.
