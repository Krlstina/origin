#ifndef BYEDYNAMIC_H
#define BYEDYNAMIC_H

#ifdef BYEDINAMICLIB_EXPORTS
#define BYEDINAMIC_API __declspec(dllexport)
#else
#define BYEDINAMIC_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>

namespace ByeDynamicLib
{
	class Leaver
	{
	public:
		void BYEDINAMIC_API leave(std::string name);
	};
}

#endif