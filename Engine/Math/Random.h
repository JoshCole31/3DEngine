#pragma once
#include <xkeycheck.h>

namespace jc
{
	void SeedRandom(unsigned int seed);

	float Random();//0-1
	float RandomRange(float min, float max);

	int Randomint();
	int Randomint(int max);
	int RandomRangeInt(int min, int max);


}