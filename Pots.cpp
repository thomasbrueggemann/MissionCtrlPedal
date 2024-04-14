#include "Pots.h"

Pots::Pots(SPI &spi) : spi(spi), digiPot(5, 6, 7, spi)
{
}