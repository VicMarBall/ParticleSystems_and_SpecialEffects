#include "Particle.h"

Particle::Particle()
{
	
}

Particle::~Particle()
{

}

void Particle::Initialize(fPoint initialPosition, fPoint initiaVelocity, fPoint acceleration, float lifespan)
{
	this->position = initialPosition;
	this->velocity = initiaVelocity;
	this->acceleration = acceleration;
	this->lifespan = lifespan;
}

void Particle::Update(float dt)
{
	lifespan -= dt;

	velocity.x += acceleration.x * dt;
	velocity.y += acceleration.y * dt;
	position.x += velocity.x * dt;
	position.y += velocity.y * dt;

}

bool Particle::IsBeingUsed()
{
	return (lifespan > 0);
}
