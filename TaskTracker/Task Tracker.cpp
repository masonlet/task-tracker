#pragma comment(lib, "Shell32.lib")

/*
Program name: Task Tracker
Purpose: Changes a folders icon to the selected buttons icon
Author: Mason L'Etoile
Date: January 26, 2025
*/

#include <iostream>
#include <filesystem>
#include <fstream>
#include <Windows.h>
#include <shlobj.h>

int error(std::string error) {
	std::cout << "Error: " << error;
	return -1;
}

int main(int argc, char* argv[]){
	if (argc != 3) return error("Invalid argument amount\n");

	std::string folderPath = argv[1];
	if (!std::filesystem::exists(folderPath) || !std::filesystem::is_directory(folderPath)) return error("Selected folder is invalid\n");

	std::string iconPath = argv[2];
	
	std::string desktopIniPath = folderPath + "\\desktop.ini";
	if (std::filesystem::exists(desktopIniPath)) DeleteFileA(desktopIniPath.c_str());

	if (iconPath == "C:\\Windows\\System32\\shell32.dll,-4") return 1;

	std::ofstream desktopIni(desktopIniPath);
	if (!desktopIni) return error("Error creating desktopIni file at " + desktopIniPath + '\n');

	desktopIni << "[.ShellClassInfo]\n";
	desktopIni << "IconResource=" << iconPath << '\n';
	desktopIni << "[ViewState]\n";
	desktopIni << "Mode=\n";
	desktopIni << "Vid=\n";
	desktopIni << "FolderType=Generic\n";
	desktopIni.close();

	if (!SetFileAttributesA(folderPath.c_str(), FILE_ATTRIBUTE_SYSTEM)) return error("Error setting folder attributes\n");
	if (!SetFileAttributesA(desktopIniPath.c_str(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM)) return error("Error setting desktop.ini attributes\n");

	SHChangeNotify(SHCNE_UPDATEDIR, SHCNF_PATH | SHCNF_FLUSHNOWAIT, folderPath.c_str(), nullptr);
}