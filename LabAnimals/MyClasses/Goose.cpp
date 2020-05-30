#include "Goose.h"


Goose::Goose() :Birds()
{
	color = 'w';
	tail = true;
	Beak = true;
	legs = 2;
	wool = false;
}

const char* Goose::Voise()
{
	return("Hello, my dear friend!");
}

void Goose::Settail(bool b)
{
	tail = b;
}

bool Goose::Gettail()
{
	return tail;
}