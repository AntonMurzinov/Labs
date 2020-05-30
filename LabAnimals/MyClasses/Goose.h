#ifndef _ducks_h_
#define _ducks_h_
#include "Birds.h"


class Goose : public Birds
{
protected:
	bool tail;
public:
	Goose();
	const char* Voise();
	void Settail(bool t);
	bool Gettail();
};

#endif
