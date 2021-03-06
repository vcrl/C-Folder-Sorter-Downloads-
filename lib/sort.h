#ifndef SORT_H
#define SORT_H

#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <ctime>
class Sort
{
	public:
		Sort() = default;
		void makeDirs();
		std::string getFileName(std::string path);
		void sortFiles();
		void chooseDestination(std::string path, std::array<std::string, 5> type, std::string folder);

	private:
		std::array<std::string, 5> exeExtensions = { ".exe", ".msi", ".iso", ".jar" };
		std::array<std::string, 5> imgExtensions = { ".png", ".jpg", ".jpeg",  ".gif", ".JPEG" };
		std::array<std::string, 5> videoExtensions = { ".mp4",  ".avi",  ".mkv", ".wmw", ".webm" };
		std::array<std::string, 5> audioExtensions = { ".mp3", ".wav", ".ogg" };
		std::array<std::string, 5> docExtensions{ ".txt", ".docx", ".pdf", ".psd", ".doc" };
		std::array<std::string, 5> compressedExtensions{ ".zip", ".rar", ".torrent", ".tar.gz" };
		std::array<std::string, 5> otherExtensions{ ".ini", ".log", ".sql", ".json" };

};

#endif // SORT_H