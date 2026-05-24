#pragma once

class Calc {
private:
	double a, b;
public:
	Calc();
	double get_a();
	double get_b();
	double addition();
	double subtraction();
	double multiplication();
	double division();
	double exponentiation();
};