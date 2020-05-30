#ifndef _Cheetah_h_
#define _Cheetah_h_
#include "mammals.h"


class Cheetah :public mammals
{
protected:
	int Spotted_skin;
public:
	Cheetah();
	void SetSpotted_skin(int a);
	int GetSpotted_skin();
};

#endif
