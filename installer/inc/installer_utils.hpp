#pragma once

#include "file_path.h"

namespace TaskTracker::Installer {
	bool isTaskTrackerInstalled();

	bool extractTaskTrackerExe(const Path& toPath);
	int installTaskTracker();

	int deleteTaskTracker();
}
