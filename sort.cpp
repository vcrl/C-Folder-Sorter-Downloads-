#include <iostream>
#include <direct.h>
#include <string>
#include <cstdio>
#include <filesystem>
#include <cstring>
#include "sort.h"

void Sort::makeDirs()
{
    std::string dirNames[] = { "Executables", "Images", "Videos", "Audio", "Documents", "Other" };
    for (std::string dir : dirNames)
    {
        if (_mkdir(dir.c_str()))
        {
            std::cout << "Created with success." << std::endl;
        }
    }
}

std::string Sort::getFileName(std::string path)
{
    std::string fileName = "";
    for (auto x : path)
    {
        if (x == '\\')
        {
            fileName = "";
        }
        else {
            fileName += x;
        }
    }
    return fileName;
}

void Sort::sortFiles()
{
    std::string path = "Test";
    for (const auto file : std::filesystem::directory_iterator(path)) // For file in directory (path)
    {
        std::string pathToString = file.path().u8string(); // Convert file path to std::string > pathToString
        
    }
}

void Sort::chooseDestination(std::string path)
{
    for (std::string ext : docExtensions) // For extension in docExtensions
    {
        if (path.substr(path.length() - 4) == ext || path.substr(path.length() - 5) == ext) // if pathToString matches extension
        {
            const char* pathToChar = &path[0]; // Convert path to const char
            std::string toFolder = "Documents/" + getFileName(path); // Prepare destination path (Documents/filename.ext)
            const char* destination = toFolder.c_str(); // Convert destination to const char
            rename(pathToChar, destination); // Moves original file to destination
        }
    }
}
