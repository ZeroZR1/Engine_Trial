#include "stdafx.h"
#include "PackageManager.h"


/*PackageManager Definition************************************************************************************************/


void PackageManager::AddPackage(std::string Name, std::string Type, std::vector<std::string> ArchiveName) {
		
		Wrapped.push_back (Package(Name, Type, ArchiveName));
}

/*std::vector<ALLEGRO_BITMAP*> PackageManager::UnpackImage(std::string PackageName) {

	std::vector<ALLEGRO_BITMAP*> Data;

	for (size_t i = 0; i < Wrapped.size(); i++)
	{

		if (Wrapped[i].Name == PackageName) {
			Data.reserve(Wrapped[i].Directory.size());

			for (size_t j = 0; j < Wrapped[i].Directory.size(); j++)
			{
				Data.push_back ((al_load_bitmap(Wrapped[i].Directory[j].c_str())));
			}
			return(Data);
		}
	}
	return(Data);
}*/

std::vector<ALLEGRO_BITMAP*> PackageManager::UnpackImage(std::string PackageName,NumCuadritos,) {

	std::vector<ALLEGRO_BITMAP*> Data;

	ALLEGRO_BITMAP* Cosa;

	Cosa = (al_load_bitmap(PackageName.c_str()));

	Data.push_back(Cosa.blit(...));
	return(Data);
}


/*Package Definition*******************************************************************************************************/

Package::Package(std::string _Name, std::string _Type, std::vector<std::string> Data)
{
	Directory.reserve(Data.size());
	Directory = Data;
	Type = _Type;
	Name = _Name;

	
}

Package::~Package(){}

/**************************************************************************************************************************/


