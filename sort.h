#include <string>
class Sort
{
	public:
		void makeDirs();
		std::string getFileName(std::string path);
		void sortFiles();
		void chooseDestination(std::string path);

	private:
		std::string exeExtension[1] = { ".exe" };
		std::string imgExtensions[5] = { ".png", ".jpg", ".jpeg",  ".gif", ".JPEG" };
		std::string videoExtensions[5] = { ".mp4",  ".avi",  ".mkv", ".wmw", ".webm" };
		std::string audioExtensions[3] = { ".mp3", ".wav", ".ogg" };
		std::string docExtensions[2] = { ".txt", ".docx" };

};

