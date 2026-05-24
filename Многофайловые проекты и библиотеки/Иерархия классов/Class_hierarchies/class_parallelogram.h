#pragma once
#include "class_quadrilateral.h"
class parallelogram : public quadrilateral {
public:
	parallelogram(int a, int b, int A, int B);
	void print() override;
};