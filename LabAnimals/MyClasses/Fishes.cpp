#include"Fishes.h"


Fishes::Fishes() :Animals()
{
	Fin = true;
	Fish_scales = true;
}

void Fishes::SetFin(bool a)
{
	Fin = a;
}

void Fishes::SetFish_scales(bool a)
{
	Fish_scales = a;
}

bool Fishes::GetFin()
{
	return Fin;
}

bool Fishes::GetFish_scales()
{
	return Fish_scales;
}