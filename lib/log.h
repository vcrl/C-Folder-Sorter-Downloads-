#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>
#include <ctime>

class Log
{
	public:
		Log() = default;
		std::time_t getTime();
		void logMakeDir(std::string dir);
		void logMoveFiles(std::string path, std::string folder);
	private:
		std::string logName = "logs.log";
};

#endif // LOG_H

