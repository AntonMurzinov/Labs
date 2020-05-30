#ifndef _BabyShark_h_
#define _BabyShark_h_
#include "Shark.h"


class BabyShark :public Shark
{
protected:
	int Length;
public:
	BabyShark();
	int GetLength();
	void SetLength(int a);
};
#endif

