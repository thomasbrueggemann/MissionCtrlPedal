#ifndef POTS_H
#define POTS_H

#include "AD520X.h"

class Pots
{
public:
	Pots(SPI &spi);

private:
	SPI &spi;
	AD5206 digiPot;
};

#endif // POTS_H