#pragma once
#include"cFizyka.h"
class cPostac : public cFizyka
{
	float a_, b_;
	float angle_;

	int punkty;
	
public:
	void rysuj();
	void rotate(int ang);
	void przesun(double dx, double dy);
	void rzut();
};
