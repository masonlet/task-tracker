#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>
#include "../inc/file_utils.hpp"
#include "../inc/system_utils.hpp"

using TPath = TaskTracker::Path;
namespace {
  TPath makeTempPath(const std::wstring& name) {
    return std::filesystem::temp_directory_path() / name;
  }
}

namespace TFile = TaskTracker::FileUtils;
TEST(FileUtils, FileExists_ReturnsTrueWhenPresent) {
  TPath path = makeTempPath(L"test_exist.txt");
  std::ofstream{ path };

  EXPECT_TRUE(TFile::fileExists(path, L"test", false));
  std::filesystem::remove(path);
}

TEST(FileUtils, DeleteFile_RemovesExistingFile) {
  TPath path = makeTempPath(L"test_delete.txt");
  std::ofstream{ path };

  EXPECT_TRUE(TFile::deleteFile(path, L"test"));
  EXPECT_FALSE(std::filesystem::exists(path));
}

TEST(FileUtils, CreateDirectory_CreatesNewDirectory) {
  TPath path = makeTempPath(L"test_create_dir");
  EXPECT_TRUE(TFile::createDirectory(path, L"test"));
  EXPECT_TRUE(std::filesystem::is_directory(path));
  std::filesystem::remove(path);
}

TEST(FileUtils, DeleteDirectory_RemovesExistingDirectory) {
  TPath path = makeTempPath(L"test_delete_dir");
  std::filesystem::create_directory(path);
  EXPECT_TRUE(TFile::deleteDirectory(path, L"test"));
  EXPECT_FALSE(std::filesystem::exists(path));
}

namespace TSystem = TaskTracker::SystemUtils;
TEST(SystemUtils, GetProgramFilesPath_ReturnsValidPath) {
  TPath path = TSystem::getProgramFilesPath();
  EXPECT_FALSE(path.empty());
  EXPECT_TRUE(std::filesystem::exists(path));
}

TEST(SystemUtils, IsValidPath_RejectsNonexistent) {
  TPath fakePath = makeTempPath(L"nonexistent_dir");
  EXPECT_FALSE(TSystem::isValidPath(fakePath, L"test"));
}

TEST(SystemUtils, IsValidPath_RejectsExistingFile) {
  TPath filePath = makeTempPath(L"not_a_dir.txt");
  std::ofstream{ filePath };
  EXPECT_FALSE(TSystem::isValidPath(filePath, L"test"));
  std::filesystem::remove(filePath);
}

TEST(SystemUtils, DeleteDesktopIni_HandlesNonexistentFile) {
  TPath path = makeTempPath(L"desktop.ini");
  EXPECT_TRUE(TSystem::deleteDesktopIni(path, L"test"));
}