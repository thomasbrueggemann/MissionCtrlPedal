#ifndef BANKS_H
#define BANKS_H

class Banks
{
public:
	Banks();

	void setPreset(byte preset);
	void bankUp();
	void bankDown();

	byte getCurrentBank();
	byte getCurrentPreset();

private:
	byte currentBank;
	byte currentPreset;
};

#endif