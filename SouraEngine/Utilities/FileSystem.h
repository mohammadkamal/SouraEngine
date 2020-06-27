#pragma once
#include <vector>
#include <string>

// Extensions to be added...
static const std::string NOT_ASSIGNED = "N/A";

class FileSystem
{
	//directories
	static bool CreateDirectory(const std::string& path);
	static bool DeleteDirectory(const std::string& directory);
	static bool DirectoryExists(const std::string& directory);
	static bool IsDirectory(const std::string& directory);
	//static void OpenDirectoryWindow(const std::string& directory);

	//files
	static bool FileExists(const std::string& filePath);
	static bool DeleteFile(const std::string& filePath);
	static bool CopyFileFromTo(const std::string& source, const std::string& destination);

	//directory parsing
	static std::string GetFileNameFromFilePath(const std::string& path);
	static std::string GetFileNameNoExtensionFromFilePath(const std::string& filePath);
	static std::string GetDirectoryFromFilePath(const std::string& filePath);
	static std::string GetFilePathWithoutExtention(const std::string& filePath);
	static std::string GetExtensionFromFilePath(const std::string& filePath);
	static std::string GetRelativeFilePath(const std::string& absoluteFilePath);
	static std::string GetWorkingDirectory();
	static std::string GetParentDirectory(const std::string& directory);
	static std::vector<std::string> GetDirectoriesInDirectory(const std::string& directory);
	static std::vector<std::string> GetFilesInDirectory(const std::string& directory);
};