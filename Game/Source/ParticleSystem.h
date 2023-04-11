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

	// to delete (put in manager)
	void SetParticleSystem(iPoint position, iPoint velocity, iPoint acceleration, 
		char initialR, char initialG, char initialB, char initialAlpha, 
		float spawnRate, float lifespan, bool isConstant, int maxParticles);

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

	char initialR;
	char initialG;
	char initialB;
	char initialAlpha;

	float spawnRate;

	float lifespan;

	bool isConstant;

	// to delete
	int maxParticles;

protected:
private:

	float timeFromLastSpawn;

	SDL_Texture* texture;
	List<Particle*> particles;
};