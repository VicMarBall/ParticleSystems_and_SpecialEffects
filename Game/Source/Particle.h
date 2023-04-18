#pragma once
#include "Point.h"

// SDL has a SDL_Color, but because of linking problems I create our own
struct Color {
	void Set(int red, int green, int blue, int alpha) {
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}

	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};


class Particle {
	// methods
public:
	Particle();
	~Particle();

	void Initialize(fPoint initialPosition, fPoint initiaVelocity, fPoint acceleration, Color initialColor, Color objectiveColor, float lifespan);

	void Update(float dt);

	void ResetParticle();

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
		return color;
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
	Color color;
	Color objectiveColor;

	float lifespan;

	Particle* next;
};