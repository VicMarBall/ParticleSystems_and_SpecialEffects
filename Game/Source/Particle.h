#pragma once
#include "Point.h"

class Particle {
	// methods
public:
	Particle();
	~Particle();

	void Initialize(fPoint initialPosition, fPoint initiaVelocity, fPoint acceleration, char red, char green, char blue, char transparency, float lifespan);

	void Update(float dt);

	bool IsBeingUsed();

protected:
private:

	// variables
public:
	fPoint position;
	fPoint velocity;
	fPoint acceleration;

	char r;
	char g;
	char b;
	char alpha;

	float lifespan;

protected:
private:

};