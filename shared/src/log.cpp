#include "log.hpp"

#include <iostream>

bool error(const std::wstring_view& message, const bool pause) {
	std::wcout << L"TaskTracker Installer [Error]: " << message << L'\n';

	if (pause) {
		std::wcout << L"Press Enter to continue...";
		std::wcin.get();
	}
	return false;
}
int error_exit(const std::wstring_view& message, const bool pause) {
    error(message, pause);
    return EXIT_FAILURE;
}
void message(const std::wstring_view& message, const bool pause) {
	std::wcout << L"TaskTracker Installer [Info]: " << message << L'\n';

	if (pause) {
		std::wcout << L"Press Enter to continue...";
		std::wcin.get();
	}
}
