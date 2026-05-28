#pragma once
#include <exception>
class MyException : public std::exception {
private:
public:
	MyException(const char* msg);

};