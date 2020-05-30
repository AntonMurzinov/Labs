#include"mammals.h"


mammals::mammals() :Animals()
{
	tail = true;
	arms = false;
	legs = 0;
	wool = 0;
	claws = 0;
}

void mammals::Setlegs(int a)
{
	legs = a;
}

void mammals::Setarms(bool a)
{
	arms = a;
}

void mammals::Settail(bool a)
{
	tail = a;
}

int mammals::Getlegs()
{
	return legs;
}

int mammals::Gettail()
{
	return tail;
}

bool mammals::Getarms()
{
	return arms;
}
