#ifndef _Fishes_h_
#define _Fishes_h_
#include "Animals.h"


class Fishes :public Animals
{
protected:
	bool Fin;
	bool Fish_scales;
public:
	Fishes();
	void SetFin(bool a);
	void SetFish_scales(bool a);
	bool GetFin();
	bool GetFish_scales();
};

#endif
