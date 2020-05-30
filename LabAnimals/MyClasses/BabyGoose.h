#ifndef _BabyGoose_h_
#define _BabyGoose_h_
#include "Goose.h"


class BabyGoose :public Goose
{
protected:
	int Weight;
public:
	BabyGoose();
	void SetWeight(int a);
	int GetWeight();
};
#endif