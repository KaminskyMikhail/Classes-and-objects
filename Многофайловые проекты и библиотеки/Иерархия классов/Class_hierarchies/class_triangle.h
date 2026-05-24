#pragma once
#include "class_figure.h"
class triangle : public figure {
protected:
	int a, b, c; // стороны
	int A, B, C; // углы
public:
	triangle(int a, int b, int c, int A, int B, int C);
	void print() override;
};