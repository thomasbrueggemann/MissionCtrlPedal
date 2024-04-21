#ifndef FAKEYTOUCH_H
#define FAKEYTOUCH_H

class FaderTouchSensor
{
public:
	FaderTouchSensor(int pin, int threshold = 300);
	void Begin();
	bool IsTouched();

private:
	int baseline;
	int threshold;
	int pin;

	int readTouch();
};

#endif // FAKEYTOUCH_H;