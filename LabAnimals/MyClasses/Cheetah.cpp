#include"Cheetah.h"


Cheetah::Cheetah() :mammals()
{
	Spotted_skin = 0;
}

void Cheetah::SetSpotted_skin(int a)
{
	Spotted_skin= a;
}

int Cheetah::GetSpotted_skin()
{
	return Spotted_skin;
}
