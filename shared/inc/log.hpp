#pragma once

#include <string>

bool error(const std::wstring_view& message, const bool pause = false);
int error_exit(const std::wstring_view& message, const bool pause = false);
void message(const std::wstring_view& message, const bool pause = false);
