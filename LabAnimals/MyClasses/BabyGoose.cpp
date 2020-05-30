#include"BabyGoose.h"


BabyGoose::BabyGoose() : Goose()
{
	Weight = 5;
}

int BabyGoose::GetWeight()
{
	return Weight;
}

void BabyGoose::SetWeight(int a)
{
	Weight = a;
}