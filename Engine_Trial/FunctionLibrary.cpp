#include "FunctionLibrary.h"

std::string IntToString(int _IntNumber)
{
	std::string Result;
	std::ostringstream convert;

	convert << _IntNumber;
	Result = convert.str();

	return std::string(Result);
}

bool Exist(std::string _FileName)
{
	if (FILE *file = fopen(_FileName.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}
