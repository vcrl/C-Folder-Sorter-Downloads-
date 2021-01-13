#include <iostream>
#include <direct.h>
#include <string>
#include <cstdio>
#include <filesystem>
#include <cstring>
#include <array>
#include <fstream>
#include <ctime>
#pragma warning(disable : 4996)
#include "sort.h"

std::time_t Sort::getTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    return currentTime;
}

void Sort::makeDirs()
{
    std::ofstream logFile(logName.c_str(), std::ios::app);
    std::string dirNames[] = { "Executables", "Images", "Videos", "Audio", "Documents", "Compressed", "Other" };
    for (std::string dir : dirNames)
    {
        if (_mkdir(dir.c_str()))
        {
            if (logFile)
            {
                auto now = getTime();
                logFile << std::ctime(&now);
                logFile << " [Created directory: " << dir << "]" <<std::endl;
            }
            else
            {
                std::cout << "Error while creating log file." << std::endl;
            }
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
    std::string path = ".";
    for (const auto file : std::filesystem::directory_iterator(path)) // For file in directory (path)
    {
        std::string pathToString = file.path().u8string(); // Convert file path to std::string > pathToString
        chooseDestination(pathToString, exeExtensions, "Executables/");
        chooseDestination(pathToString, imgExtensions, "Images/");
        chooseDestination(pathToString, videoExtensions, "Videos/");
        chooseDestination(pathToString, audioExtensions, "Audio/");
        chooseDestination(pathToString, docExtensions, "Documents/");
        chooseDestination(pathToString, compressedExtensions, "Compressed/");
        chooseDestination(pathToString, otherExtensions, "Other/");
        
    }
}

void Sort::chooseDestination(std::string path, std::array<std::string, 5> type, std::string folder)
{
    std::ofstream logFile(logName.c_str(), std::ios::app); // Locate log file logs.log
    auto now = getTime(); // Store current time

    for (std::string ext : type) // For extension in extensions_array (type)
    {
        if (path.substr(path.length() - 4) == ext && getFileName(path) != "logs.log" || 
            path.substr(path.length() - 5) == ext && getFileName(path) != "logs.log") // if pathToString matches extension
        {
            logFile << std::ctime(&now); // Write current time in logs.log
            logFile << " [Moved file: " << path << " to " << folder << "]" << std::endl; // Writes moved files in logs.log
            const char* pathToChar = &path[0]; // Convert path to const char
            std::string toFolder = folder + getFileName(path); // Prepare destination path (Documents/filename.ext)
            const char* destination = toFolder.c_str(); // Convert destination to const char
            if (rename(pathToChar, destination)) // Moves original file to destination
            {
                std::cout << "Succeeded";
            } 
        }
    }
}
