#ifndef _Animals_h_
#define _Animals_h_


class Animals
{
protected:
	char color;
	bool wool;
	bool claws;
public:
	char getcolor();
	int getwool();
	int getclaws();

	void setcolor(char a);
	void setwool(bool b);
	void setclaws(bool c);
	Animals();
};
#endif