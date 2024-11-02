#include "ByeDynamic.h"

namespace ByeDynamicLib
{
	void Leaver::leave(std::string name)
	{
		std::cout << "До свидания, " << name << "!" << std::endl;
	}
}