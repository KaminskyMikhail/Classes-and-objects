#pragma once
#include "class_triangle.h"
class right_triangle : public triangle {
public:
	right_triangle(int a, int b, int c, int A, int C);
	void print() override;
};