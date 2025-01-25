/*
Program name: Task Tracker
Purpose: Adds three new buttons to the windows right click menu: Finished, Unfinished, and Hidden
Author: Mason L'Etoile
Date: January 24, 2025
*/

#include <iostream>
#include <Windows.h>

const char* regPath = R"(Directory\shell\)";

bool cmdExists(std::string name) {
	HKEY hKey;

	if (RegOpenKeyExA(HKEY_CLASSES_ROOT, (std::string(regPath) + '\\' + name).c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
		RegCloseKey(hKey);
		return true;
	}

	return false;
}

void removeCmd(std::string name) {
	RegDeleteKeyA(HKEY_CLASSES_ROOT,(std::string(regPath) + '\\' + name).c_str());
	std::cout << "Command " + name + " Removed\n";
}

void addCmd(std::string name) {
	HKEY hKey;
	DWORD disposition;

	if (RegCreateKeyExA(HKEY_CLASSES_ROOT, (std::string(regPath) + '\\' + name).c_str(), 0, NULL, 0, KEY_WRITE, NULL, &hKey, &disposition) == ERROR_SUCCESS) {
		RegCloseKey(hKey);

		std::cout << "Command " + name + " Added\n";
	} else {
		std::cout << "Error creating " +  name + " registry key\n";
	}
}

int main() {
	if (cmdExists("Finished") || cmdExists("Unfinished") || cmdExists("Hidden")) {	
		removeCmd("Finished");
		removeCmd("Unfinished");
		removeCmd("Hidden");
	}
	else {
		addCmd("Finished");
		addCmd("Unfinished");
		addCmd("Hidden");
	}
}