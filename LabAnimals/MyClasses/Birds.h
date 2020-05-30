#ifndef _Birds_h_
#define _Birds_h_
#include "Animals.h"


class Birds : public Animals
{
protected:
	bool Beak;
	int legs;
public:
	Birds();
	void SetBeak(bool a);
	bool GetBeak();
	void Setlegs(int b);
	int Getlegs();
};
#endif