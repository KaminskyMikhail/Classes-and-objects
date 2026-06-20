#pragma once
#include <iostream>
#ifdef LEAVELIB_EXPORTS
#define LEAVELIB_API __declspec(dllexport)
#else
#define LEAVELIB_API __declspec(dllimport)
#endif
class Leaver {
private:
	std::string var = "Goodbye, ";
public:
	Leaver() = default;
	LEAVELIB_API std::string leave(std::string a) const;
};