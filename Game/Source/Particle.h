#pragma once
#include "Point.h"

class Particle {
	// methods
public:
	Particle();
	~Particle();

	void Initialize(fPoint initialPosition, fPoint initiaVelocity, fPoint acceleration, float lifespan);

	void Update(float dt);

	bool IsBeingUsed();

protected:
private:

	// variables
public:
	fPoint position;
	fPoint velocity;
	fPoint acceleration;

	float lifespan;

protected:
private:

};