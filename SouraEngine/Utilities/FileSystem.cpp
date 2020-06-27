#include "FileSystem.h"
#include <filesystem>
#include <regex>
#include <fstream>
#include <sstream>
#include <iostream>

bool FileSystem::CreateDirectory(const std::string & path)
{
	try
	{
		return std::filesystem::create_directories(path);
	}
	catch (std::filesystem::filesystem_error& e)
	{
		std::cout << "Error directory creation: " << e.what() << ", at " << path.c_str();
		return true;
	}
}

bool FileSystem::DeleteDirectory(const std::string & directory)
{
	try
	{
		return std::filesystem::remove_all(directory);
	}
	catch (std::filesystem::filesystem_error& e)
	{
		std::cout << "Error directory deletion: " << e.what() << ", at " << directory.c_str();
		return true;
	}
}

bool FileSystem::DirectoryExists(const std::string & directory)
{
	try
	{
		return std::filesystem::exists(directory);
	}
	catch (std::filesystem::filesystem_error& e)
	{
		std::cout << "Error at DirectoryExists: " << e.what() << ", at " << directory.c_str();
		return true;
	}
}

bool FileSystem::IsDirectory(const std::string & directory)
{
	try
	{
		return std::filesystem::is_directory(directory);
	}
	catch (std::filesystem::filesystem_error& e)
	{
		std::cout << "Error at IsDirectory: " << e.what() << ", at directory " << directory.c_str();
		return true;
	}
}

bool FileSystem::FileExists(const std::string & filePath)
{
	try
	{
		return std::filesystem::exists(filePath);
	}
	catch (std::filesystem::filesystem_error& e)
	{
		std::cout << "Error at FileExists: " << e.what() << ", at " << filePath.c_str();
		return true;
	}
}

bool FileSystem::DeleteFile(const std::string & filePath)
{
	//if it's a directory's path NOT a file then return false
	if (std::filesystem::is_directory(filePath))
	{
		return false;
	}

	try
	{
		return std::filesystem::remove(filePath);
	}
	catch (std::filesystem::filesystem_error& e)
	{
		std::cout << "Error at DeleteFile: " << e.what() << ", at " << filePath.c_str();
		return true;
	}
}

bool FileSystem::CopyFileFromTo(const std::string & source, const std::string & destination)
{
	//If File exists in both locations
	if (source == destination)
		return true;

	// In case the destination path doesn't exist, create it
	if (!DirectoryExists(GetDirectoryFromFilePath(destination)))
	{
		CreateDirectory(GetDirectoryFromFilePath(destination));
	}

	try
	{
		return std::filesystem::copy_file(source, destination);
	}
	catch (std::filesystem::filesystem_error& e)
	{
		std::cout << "File didn't copy because: " << e.what();
	}
}

std::string FileSystem::GetFileNameFromFilePath(const std::string & path)
{
	auto lastIndex = path.find_last_of("\\/");
	auto fileName = path.substr(lastIndex + 1, path.length());
	return fileName;
}

std::string FileSystem::GetFileNameNoExtensionFromFilePath(const std::string & filePath)
{
	auto fileName = GetFileNameFromFilePath(filePath);
	auto lastIndex = fileName.find_last_of('.');
	auto fileNameNoExtension = fileName.substr(0, lastIndex);
	return fileNameNoExtension;
}

std::string FileSystem::GetDirectoryFromFilePath(const std::string & filePath)
{
	auto lastIndex = filePath.find_last_of("\\/");
	auto directory = filePath.substr(0, lastIndex + 1);
	return directory;
}

std::string FileSystem::GetFilePathWithoutExtention(const std::string & filePath)
{
	auto directory = GetDirectoryFromFilePath(filePath);
	auto fileNameNoExtension = GetFileNameNoExtensionFromFilePath(filePath);
	return directory + fileNameNoExtension;
}

std::string FileSystem::GetExtensionFromFilePath(const std::string & filePath)
{
	if (filePath.empty() || filePath==NOT_ASSIGNED)
	{
		return NOT_ASSIGNED;
	}

	auto lastIndex = filePath.find_last_of('.');
	if (std::string::npos != lastIndex)
	{
		// extension with dot included
		return filePath.substr(lastIndex, filePath.length());
	}

	return NOT_ASSIGNED;
}
