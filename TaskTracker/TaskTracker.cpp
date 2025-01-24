/*
Program name: Task Tracker
Purpose: Adds three new buttons to the windows right click menu: Finished, Unfinished, and Unaccessable
Author: Mason L'Etoile
Date: January 24, 2025
*/

#include <iostream>
#include <Windows.h>

const char* regPath = R"(Directory\shell\TaskTracker)";
const char* cmdPath = R"(Directory\shell\TaskTracker\command)";

bool cmdExists() {
	HKEY hKey;

	std::cout << regPath << '\n';

	if (RegOpenKeyExA(HKEY_CLASSES_ROOT, cmdPath, 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
		RegCloseKey(hKey);
		return true;
	}
	else {
		return false;
	}
}

void removeCmd() {
	std::cout << "Removed";
}

void addCmd() {
	std::cout << "Added";
}

int main() {
	if (cmdExists()) {
		removeCmd();
	}
	else {
		addCmd();
	}
}