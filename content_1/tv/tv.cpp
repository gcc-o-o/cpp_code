//tv.cpp -- methods for Tv class (clss Remote methods are inline)
#include "tv.h"
#include <iostream>

bool Tv::volup()
{
	if (volume < MaxVol)
	{
		volume++;
		return true;
	}
	else return false;
}

bool Tv::voldown()
{
	if (volume > MinVol)
	{
		volume--;
		return true;
	}
	else return false;
}

void Tv::chanup()
{
	if (channel < maxChannel)
		channel++;
	else channel = 1;
}

void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else channel = maxChannel;
}

void Tv::settings() const
{
	using std::cout;
	using std::endl;
	cout << "TV is " << (state == On ? "on" : "off") << endl;
	if (state == On)
	{
		cout << "Volume: " << volume << endl
		<< "Max channel: " << maxChannel << endl
		<< "current channel: " << channel << endl
		<< "Mode: " << (mode == Antenna ? "antenna" : "cable") << endl
		<< "Input: " << (input == TV ? "TV" : "DVD") << endl;
	}
}