#pragma once

#include <string>

bool logInfo(const std::wstring_view& message, const bool ret = true);
bool logError(const std::wstring_view& message, const bool pause = false);

int success(const std::wstring_view& message);
int error(const std::wstring_view& message);