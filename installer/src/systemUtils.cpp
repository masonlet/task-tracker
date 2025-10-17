#include "systemUtils.hpp"
#include "log.hpp"

bool isAdmin() {
	HANDLE hToken{ nullptr };
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
		return log(L"OpenProcessTokenFailed", true);

	TOKEN_ELEVATION elevation{};
	DWORD returnSize = sizeof(TOKEN_ELEVATION);
	GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &returnSize);

	if (hToken) CloseHandle(hToken);
	return elevation.TokenIsElevated;
}

Path getProgramFilesPath() {
	wchar_t* path{ nullptr };
	if (FAILED(SHGetKnownFolderPath(FOLDERID_ProgramFiles, 0, nullptr, &path))) 
		return L"C:\\Program Files\\";

	Path out(path);
	CoTaskMemFree(path);
	return out;
}