#pragma comment(lib, "Shell32.lib")

#include "systemUtils.hpp"
#include "log.hpp"

#include <fstream>
#include <shlobj.h>

int wmain(int argc, wchar_t* argv[]){
	if (argc != 3) return TaskTracker::Log::exitError(L"Invalid argument amount\nUsage: TaskTracker.exe <folder_path> <icon_path>");

	const TaskTracker::Path& folder{ argv[1] };
	if (!TaskTracker::SystemUtils::isValidPath(folder)) 
		return TaskTracker::Log::exitError(L"Failed to set folder icon");

	const TaskTracker::Path desktopIni{ folder / "desktop.ini" };
	if (!TaskTracker::SystemUtils::deleteDesktopIni(desktopIni))
		return TaskTracker::Log::exitError(L"Failed to delete desktop.ini file");

	const TaskTracker::Path& icon{ argv[2] };
	if (icon.wstring() == L"C:\\Windows\\System32\\shell32.dll,-4")
		return TaskTracker::SystemUtils::exitAndRefresh(folder);

	std::wofstream desktopIniFile(desktopIni);
	if (!desktopIniFile) 
		return TaskTracker::Log::exitError(L"Failed to create desktopIni file at " + desktopIni.wstring());
	
	desktopIniFile << L"[.ShellClassInfo]\n" 
								 << L"IconResource=" << icon.wstring() << L'\n'
								 << L"[ViewState]\n"
								 << L"Mode=\n"
								 << L"Vid=\n"
								 << L"FolderType=Generic\n";
	desktopIniFile.close();

	if (!SetFileAttributesW(folder.c_str(), FILE_ATTRIBUTE_SYSTEM))
		return TaskTracker::Log::exitError(L"Failed to set folder attributes");
	if (!SetFileAttributesW(desktopIni.c_str(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM))
		return TaskTracker::Log::exitError(L"Failed to set desktop.ini attributes");

	return TaskTracker::SystemUtils::exitAndRefresh(folder);
}