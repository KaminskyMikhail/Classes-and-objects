#pragma once
#include "class_triangle.h"
class isosceles_triangle : public triangle {
public:
	isosceles_triangle(int a, int b, int A, int B);
	void print() override;
};
