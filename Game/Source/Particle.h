#pragma once
#include "Point.h"





class Particle {
public:
	iPoint position;
	iPoint velocity;
	iPoint acceleration;

	float lifetime;

	void Update();
};