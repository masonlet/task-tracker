#include "installerUtils.hpp"

#include "registryUtils.hpp"
#include "fileUtils.hpp"
#include "resource.h"
#include "log.hpp"

#include <fstream>

bool isTaskTrackerInstalled() {
	const bool installed{ registryKeyExists(REGISTRY_PATH) || fileExists(getFilePath(), true) };
	if(installed) logInfo(L"Uninstalling Task Tracker\n");
	else          logInfo(L"Installing Task Tracker\n");
	return installed;
}

bool extractTaskTrackerExe(const Path& toPath) {
	HRSRC resource = FindResource(NULL, MAKEINTRESOURCE(TASKTRACKER_EXE), RT_RCDATA);
	if (!resource) return error(L"Failed to find TaskTracker.exe resource");

	HGLOBAL resourceLoaded = LoadResource(NULL, resource);
	if (!resourceLoaded) return error(L"Failed to load TaskTracker.exe resource");

	LPVOID resourceData = LockResource(resourceLoaded);
	if (!resourceData) return error(L"Failed to lock TaskTracker.exe resource");

	DWORD resourceSize = SizeofResource(NULL, resource);
	if (resourceSize == 0) return error(L"TaskTracker.exe resource has zero size");

	std::ofstream outFile(toPath, std::ios::binary);
	if (!outFile) return error(L"Failed to create file at " + toPath.wstring());

	outFile.write(static_cast<const char*>(resourceData), resourceSize);
	outFile.close();
	return outFile.good()
		? logInfo(L"Successfully extracted TaskTracker.exe to " + toPath.wstring() + L'\n')
		: logError(L"Failed to extract TaskTracker.exe to " + toPath.wstring() + L'\n');
}

int deleteTaskTracker() {
	if (!deleteTaskTrackerKeys())
		return error(L"Failed to delete keys");

	if (!deleteFile(getExePath()))
		return error(L"Failed to delete executable at " + getExePath().wstring());

	if (!deleteDirectory(getFilePath()))
		return error(L"Failed to delete directory at " + getFilePath().wstring());

	return success(L"Uninstallation Completed");
}

int installTaskTracker() {
	if (!createTaskTrackerKeys())
		return error(L"Failed to create Task Tracker Keys");

	if (!createDirectory(getFilePath()))
		return error(L"Failed to create Task Tracker Directory");

	if (!extractTaskTrackerExe(getExePath()))
		return error(L"Failed to extract Task Tracker EXE");

	return success(L"Installation Completed");
}