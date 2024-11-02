#include "HelloStatic.h"

namespace HelloStaticLib
{
	void Greeter::greet(std::string name)
	{
		std::cout << "Здравствуйте, " << name << "!" << std::endl;
	}
}