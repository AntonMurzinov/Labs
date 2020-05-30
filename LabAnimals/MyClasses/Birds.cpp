#include"Birds.h"
#include"stdlib.h"


Birds::Birds() :Animals()
{
	color = 'c';
	wool = false;
	claws = true;
	Beak = true;
	legs = 0;

}

void Birds::SetBeak(bool a)
{
	Beak = a;
}

bool Birds::GetBeak()
{
	return Beak;
}

void Birds::Setlegs(int b)
{
	legs = b;
}

int Birds::Getlegs()
{
	return legs;
}