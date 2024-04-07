#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer
{
public:
	Potentiometer(int pin);
	int getValue();

private:
	int pin;
};

#endif // POTENTIOMETER_H