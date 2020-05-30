#ifndef _mammals_h_
#define _mammals_h_
#include "Animals.h"


class mammals :public Animals
{
protected:
	int legs;
	bool tail;
	bool arms;
public:
	mammals();
	void Setlegs(int a);
	void Setarms(bool a);
	void Settail(bool a);
	bool Getarms();
	int Getlegs();
	int Gettail();
};

#endif