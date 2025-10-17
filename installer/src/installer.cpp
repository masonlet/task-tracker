#include "systemUtils.hpp"
#include "installerUtils.hpp"
#include "log.hpp"

int wmain() {
	if (!isAdmin()) 
		return MessageBoxW(NULL, L"Must be ran as administrator", L"Error", MB_OK | MB_ICONERROR), EXIT_FAILURE;

	COMInitializer t{};
	return isTaskTrackerInstalled() ? deleteTaskTracker() : installTaskTracker();
}