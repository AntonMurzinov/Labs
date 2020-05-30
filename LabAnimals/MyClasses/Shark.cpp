#include"Shark.h"


Shark::Shark() :Fishes()
{
	predator = true;
	Age = 0;
	Fin = true;
	color = 'S';
	claws = false;
	wool = false;
}

void Shark::SetAge(int a)
{
	Age = a;
}

void Shark::Setpredator(bool a)
{
	predator = a;
}
int Shark::GetAge()
{
	return Age;
}

bool Shark::Getpredator()
{
	return predator;
}