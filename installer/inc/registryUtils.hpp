#pragma once

#include "filePath.h"
#include "systemUtils.hpp"

#include <string>
#include <filesystem>

const std::wstring REGISTRY_PATH = L"Directory\\shell\\Task Tracker";

bool createTaskTrackerKeys();
bool deleteTaskTrackerKeys();

bool registryKeyExists(const std::wstring& path);
bool createRegistryKey(const HKEY hKey, const std::wstring& path, RegKey& hKeyHandle, DWORD& disposition);
bool deleteRegistryKey(const std::wstring& path);
bool setRegistryValue(RegKey& hKey, const std::wstring_view& valueName, const std::wstring& value);
