#ifndef _Shark_h_
#define _Shark_h_
#include "Fishes.h"


class Shark :public Fishes
{
protected:
	bool predator;
	int Age;
public:
	Shark();
	void SetAge(int a);
	void Setpredator(bool a);
	bool Getpredator();
	int GetAge();
};

#endif