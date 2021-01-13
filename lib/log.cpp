#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <ctime>
#pragma warning(disable : 4996)
#include "log.h"

std::time_t Log::getTime()
{
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
	return currentTime;
}

void Log::logMakeDir(std::string dir)
{
	std::ofstream logFile(logName.c_str(), std::ios::app);
	auto now = getTime();
	logFile << std::ctime(&now);
	logFile << " [Created directory: " << dir << "]" << std::endl;

}

void Log::logMoveFiles(std::string path, std::string folder)
{
	std::ofstream logFile(logName.c_str(), std::ios::app);
	auto now = getTime();
	logFile << std::ctime(&now); // Write current time in logs.log
	logFile << " [Moved file: " << path << " to " << folder << "]" << std::endl; // Writes moved files in logs.log
	
}
