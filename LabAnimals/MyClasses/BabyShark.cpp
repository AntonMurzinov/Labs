#include"BabyShark.h"


BabyShark::BabyShark() :Shark()
{
	Length = 10;
}

int BabyShark::GetLength()
{
	return Length;
}

void BabyShark::SetLength(int a)
{
	Length = a;
}