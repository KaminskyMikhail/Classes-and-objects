#include "class_myexception.h"
MyException::MyException(const char* msg) : std::exception(msg) {}