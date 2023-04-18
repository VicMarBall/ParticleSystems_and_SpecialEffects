#pragma once
#include "Point.h"

// SDL has a SDL_Color, but because of linking problems I create our own
struct Color {
	char r;
	char g;
	char b;
	char a;
};


class Particle {
	// methods
public:
	Particle();
	~Particle();

	void ResetParticle();

	void Initialize(fPoint initialPosition, fPoint initiaVelocity, fPoint acceleration, char red, char green, char blue, char transparency, float lifespan);

	void Update(float dt);

	bool IsBeingUsed();

	// get the next free particle in the pool
	Particle* GetNext() const {
		return next;
	}

	void SetNext(Particle* next) {
		this->next = next;
	}

	fPoint GetPosition() const {
		return position;
	}

	Color GetColor() const {
		return initialColor;
	}

protected:
private:

	// variables
public:
	

protected:
private:

	float timeLeft;

	fPoint position;
	fPoint velocity;
	fPoint acceleration;

	Color initialColor;
	Color objectiveColor;

	float lifespan;

	Particle* next;
};