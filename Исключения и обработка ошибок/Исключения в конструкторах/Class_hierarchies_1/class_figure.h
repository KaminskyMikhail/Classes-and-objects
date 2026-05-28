#pragma once
#include "class_Interface.h"
#include <iostream>
#include "string"
class figure : Interface {
protected:
	std::string name;
public:
	void print() override;
};