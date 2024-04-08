#ifndef SEGMENTDISPLAY_H
#define SEGMENTDISPLAY_H

#include <Arduino.h>

#define SEGMENT_A_PIN 7
#define SEGMENT_B_PIN 6
#define SEGMENT_C_PIN 5
#define SEGMENT_D_PIN 11
#define SEGMENT_E_PIN 10
#define SEGMENT_F_PIN 8
#define SEGMENT_G_PIN 9

class SegmentDisplay
{
public:
  SegmentDisplay();
	void DisplayNumber(byte number);

private:
	void display1();
	void display2();
	void display3();
	void display4();
	void display5();
	void display6();
	void display7();
	void display8();
	void display9();
	void display0();
	void clearDisplay();
};

#endif // SEGMENTDISPLAY_H