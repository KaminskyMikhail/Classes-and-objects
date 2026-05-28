#pragma once
#include "class_rectangle.h"
class square : public rectangle {
public:
	square(int a);
	void print() override;
};