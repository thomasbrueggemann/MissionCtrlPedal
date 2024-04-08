#include "SegmentDisplay.h"

SegmentDisplay::SegmentDisplay()
{
	pinMode(SEGMENT_A_PIN, OUTPUT);
	pinMode(SEGMENT_B_PIN, OUTPUT);
	pinMode(SEGMENT_C_PIN, OUTPUT);
	pinMode(SEGMENT_D_PIN, OUTPUT);
	pinMode(SEGMENT_E_PIN, OUTPUT);
	pinMode(SEGMENT_F_PIN, OUTPUT);
	pinMode(SEGMENT_G_PIN, OUTPUT);
};

void SegmentDisplay::DisplayNumber(byte number)
{
	clearDisplay();

	switch (number)
	{
	case 0:
		display0();
		break;
	case 1:
		display1();
		break;
	case 2:
		display2();
		break;
	case 3:
		display3();
		break;
	case 4:
		display4();
		break;
	case 5:
		display5();
		break;
	case 6:
		display6();
		break;
	case 7:
		display7();
		break;
	case 8:
		display8();
		break;
	case 9:
		display9();
		break;
	}
};

void SegmentDisplay::display1(void)
{
	digitalWrite(SEGMENT_B_PIN, HIGH);
	digitalWrite(SEGMENT_C_PIN, HIGH);
};

void SegmentDisplay::display2(void)
{
	digitalWrite(SEGMENT_A_PIN, HIGH);
	digitalWrite(SEGMENT_B_PIN, HIGH);
	digitalWrite(SEGMENT_G_PIN, HIGH);
	digitalWrite(SEGMENT_E_PIN, HIGH);
	digitalWrite(SEGMENT_D_PIN, HIGH);
};

void SegmentDisplay::display3(void)
{
	digitalWrite(SEGMENT_A_PIN, HIGH);
	digitalWrite(SEGMENT_B_PIN, HIGH);

	digitalWrite(SEGMENT_C_PIN, HIGH);
	digitalWrite(SEGMENT_D_PIN, HIGH);
	digitalWrite(SEGMENT_G_PIN, HIGH);
};

void SegmentDisplay::display4(void)
{
	digitalWrite(SEGMENT_F_PIN, HIGH);
	digitalWrite(SEGMENT_B_PIN, HIGH);
	digitalWrite(SEGMENT_G_PIN, HIGH);
	digitalWrite(SEGMENT_C_PIN, HIGH);
};

void SegmentDisplay::display5(void)
{
	digitalWrite(SEGMENT_A_PIN, HIGH);
	digitalWrite(SEGMENT_F_PIN, HIGH);
	digitalWrite(SEGMENT_G_PIN, HIGH);
	digitalWrite(SEGMENT_C_PIN, HIGH);
	digitalWrite(SEGMENT_D_PIN, HIGH);
};

void SegmentDisplay::display6(void)
{
	digitalWrite(SEGMENT_A_PIN, HIGH);
	digitalWrite(SEGMENT_F_PIN, HIGH);
	digitalWrite(SEGMENT_G_PIN, HIGH);
	digitalWrite(SEGMENT_C_PIN, HIGH);
	digitalWrite(SEGMENT_D_PIN, HIGH);
	digitalWrite(SEGMENT_E_PIN, HIGH);
};

void SegmentDisplay::display7(void)
{
	digitalWrite(SEGMENT_A_PIN, HIGH);
	digitalWrite(SEGMENT_B_PIN, HIGH);
	digitalWrite(SEGMENT_C_PIN, HIGH);
};

void SegmentDisplay::display8(void)
{
	digitalWrite(SEGMENT_A_PIN, HIGH);
	digitalWrite(SEGMENT_B_PIN, HIGH);
	digitalWrite(SEGMENT_G_PIN, HIGH);
	digitalWrite(SEGMENT_C_PIN, HIGH);
	digitalWrite(SEGMENT_D_PIN, HIGH);
	digitalWrite(SEGMENT_E_PIN, HIGH);
	digitalWrite(SEGMENT_F_PIN, HIGH);
};

void SegmentDisplay::clearDisplay(void)
{
	digitalWrite(SEGMENT_A_PIN, LOW);
	digitalWrite(SEGMENT_B_PIN, LOW);
	digitalWrite(SEGMENT_G_PIN, LOW);
	digitalWrite(SEGMENT_C_PIN, LOW);
	digitalWrite(SEGMENT_D_PIN, LOW);
	digitalWrite(SEGMENT_E_PIN, LOW);
	digitalWrite(SEGMENT_F_PIN, LOW);
};

void SegmentDisplay::display9(void)
{
	digitalWrite(SEGMENT_A_PIN, HIGH);
	digitalWrite(SEGMENT_B_PIN, HIGH);
	digitalWrite(SEGMENT_G_PIN, HIGH);
	digitalWrite(SEGMENT_C_PIN, HIGH);
	digitalWrite(SEGMENT_D_PIN, HIGH);
	digitalWrite(SEGMENT_F_PIN, HIGH);
};

void SegmentDisplay::display0(void)
{
	digitalWrite(SEGMENT_A_PIN, HIGH);
	digitalWrite(SEGMENT_B_PIN, HIGH);
	digitalWrite(SEGMENT_C_PIN, HIGH);
	digitalWrite(SEGMENT_D_PIN, HIGH);
	digitalWrite(SEGMENT_E_PIN, HIGH);
	digitalWrite(SEGMENT_F_PIN, HIGH);
};