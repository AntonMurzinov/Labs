#include"BabyCheetah.h"


BabyCheetah::BabyCheetah() : Cheetah()
{
	Height = 1;
}

float BabyCheetah::GetHeight()
{
	return Height;
}

void BabyCheetah::SetHeight(float a)
{
	Height = a;
}