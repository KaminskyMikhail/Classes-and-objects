#pragma once
#include "class_quadrilateral.h"
class rectangle : public quadrilateral {
public:
	rectangle(int a, int b);
	void print() override;
};