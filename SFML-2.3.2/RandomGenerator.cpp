#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() {
	srand((unsigned)time(nullptr));
}

float RandomGenerator::rand_f(int n)
{	
	float x = (rand() % n + 1.0f);	
	return x;
}

int RandomGenerator::rand_i(int n) {	
	return rand() % n;
}

RandomGenerator::~RandomGenerator()
{
}
