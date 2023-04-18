#include "Particle.h"

Particle::Particle()
{
	
}

Particle::~Particle()
{

}

void Particle::ResetParticle()
{
	timeLeft = -1;
}

void Particle::Initialize(fPoint initialPosition, fPoint initiaVelocity, fPoint acceleration, char red, char green, char blue, char transparency, float lifespan)
{
	this->position = initialPosition;
	this->velocity = initiaVelocity;
	this->acceleration = acceleration;

	this->initialColor = Color{ red, green, blue, transparency };

	/*this->r = red;
	this->g = green;
	this->b = blue;
	this->alpha = transparency;*/

	this->lifespan = lifespan;

	timeLeft = lifespan;
}

void Particle::Update(float dt)
{
	timeLeft -= dt;

	velocity.x += acceleration.x * dt;
	velocity.y += acceleration.y * dt;
	position.x += velocity.x * dt;
	position.y += velocity.y * dt;

}

bool Particle::IsBeingUsed()
{
	return (timeLeft > 0);
}
