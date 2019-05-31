#pragma once
#include <vector>

#if __linux__
#include <string.h>
#elif _WINDOWS
#include <string>
#endif
//allegro libraries
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

/*A package and its manager are classes meant to 
help with asset handling.
Rigth now it lacks support for:

Sound
Video
Texture Atlas

*/
class Package {
public:
	std::string Type;//Will be used when we introduce other package types
	std::string Name;
	std::vector<std::string> Directory;


	Package(std::string Name, std::string Type, std::vector<std::string> Data);

	~Package();
};


class PackageManager {
public:

	std::vector<Package> Wrapped;

	PackageManager() {};

	~PackageManager() {};

	void AddPackage(std::string _Name, std::string _Type, std::vector<std::string> ArchiveName);

	std::vector<ALLEGRO_BITMAP*> UnpackImage(std::string PackageName);

};