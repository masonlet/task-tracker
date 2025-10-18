#include "fileUtils.hpp"
#include "log.hpp"

#include <fstream>

bool fileExists(const Path& path, const bool verbose) {
	return std::filesystem::exists(path)
		? verbose 
			? logInfo(L"File found at " + path.wstring()) 
			: true 
		: verbose 
			? logInfo(L"File not found at " + path.wstring(), false) 
			: false;
}
bool deleteFile(const Path& path) {
	if(!fileExists(path, false))
		return logInfo(L"No file to remove at " + path.wstring());

	if (!std::filesystem::remove(path)) 
		return logError(L"Failed to remove file at " + path.wstring());
	
	return fileExists(path, false)
		? logError(L"Failed to remove file at " + path.wstring())
		: logInfo(L"File Removed at " + path.wstring());
}

bool isDirectory(const Path& path, const bool verbose) {
	return std::filesystem::is_directory(path)
		? verbose 
		  ? logInfo(L"Directory found at " + path.wstring())
		  : true
		: verbose 
		  ? logInfo(L"Directory not found at " + path.wstring(), false)
		  : false;
}
bool deleteDirectory(const Path& path) {
	if(!fileExists(path, false))
		return logInfo(L"No directory to remove at " + path.wstring());

	if (!std::filesystem::remove_all(path)) 
		return logError(L"Failed to remove directory at " + path.wstring());

	return isDirectory(path, false)
		? logError(L"Failed to remove directory at " + path.wstring())
		: logInfo(L"Directory Removed at " + path.wstring());
}
bool createDirectory(const Path& path) {
	if (!fileExists(path, true) && !std::filesystem::create_directories(path))
		return error(L"Failed to create TaskTracker folder at " + path.wstring());

	return fileExists(path, false)
		? logInfo(L"Folder added at " + path.wstring())
		: logError(L"Failed to create folder at " + path.wstring());
}
