#include "Animals.h"
#include "string.h"


Animals::Animals()
{
	color = 'g';
	wool = 0;
	claws = 0;
}

char Animals::getcolor()
{
	return color;
}

int Animals::getwool()
{
	return wool;
}

int Animals::getclaws()
{
	return claws;
}

void Animals::setcolor(char a)
{
	color = a;
}

void Animals::setwool(bool w)
{
	wool = w;
}

void Animals::setclaws(bool c)
{
	claws = c;
}