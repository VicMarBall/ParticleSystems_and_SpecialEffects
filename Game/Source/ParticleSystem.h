#pragma once

#include "Point.h"
#include "Textures.h"
#include "List.h"
#include "Particle.h"

class ParticleSystem {
	// methods
public:
	ParticleSystem();
	~ParticleSystem();

	void Start();
	void Update(float dt);
	void PostUpdate();

protected:
private:

	// variables
public:
	iPoint position;
	iPoint velocity;
	iPoint acceleration;

	float spawnRate;

	float lifespan;

protected:
private:
	float timeFromLastSpawn;

	SDL_Texture* texture;
	List<Particle*> particles;
};