#ifndef _BabyCheetah_h_
#define _BabyCheetah_h_
#include "Cheetah.h"


class BabyCheetah :public Cheetah
{
protected:
	float Height;
public:
	BabyCheetah();
	float GetHeight();
	void SetHeight(float a);
};
#endif
