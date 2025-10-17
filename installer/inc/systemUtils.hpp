#pragma once

#include "filePath.h"

#include <shlobj_core.h>

struct RegKey {
	HKEY hKey = nullptr;

	RegKey() = default;
	~RegKey() {
		if (hKey) RegCloseKey(hKey);
	}

	RegKey(const RegKey&) = delete;
	RegKey& operator=(const RegKey&) = delete;

	operator HKEY() const { return hKey; }

	HKEY* operator&() { return &hKey; }
};

struct SubKey {
	const std::wstring name;
	const Path path;
	const std::wstring iconPath;
};

struct COMInitializer {
	COMInitializer() {
		if (FAILED(CoInitializeEx(NULL, COINIT_MULTITHREADED)))
			throw std::runtime_error("COM initializer failed");
	}
	~COMInitializer() { CoUninitialize(); }
};

bool isAdmin();

constexpr std::wstring_view EXE_NAME = L"TaskTracker.exe";

Path getProgramFilesPath();
inline Path getFilePath() { return getProgramFilesPath() / "Task Tracker"; }
inline Path getExePath() { return getFilePath() / EXE_NAME; }