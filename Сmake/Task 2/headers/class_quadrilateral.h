#pragma once
#include "class_figure.h"
class quadrilateral : public figure {
protected:
	int a, b, c, d;
	int A, B, C, D;
public:
	quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
	void print() override;
};