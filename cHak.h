#pragma once
#include "cFizyka.h"
class cHak:public cFizyka
{
	double a_, b_;
	float angle_;
public:
	void rysuj();
	void przesun(double dx, double dy);
};