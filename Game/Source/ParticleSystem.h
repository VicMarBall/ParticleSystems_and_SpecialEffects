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

	void SetObjective(int x, int y);

	void Start();
	bool Update(float dt);
	void PostUpdate();

	void CleanParticles();

	void AssignParticle(Particle* particle);

	List<Particle*> GetParticleList() const {
		return particles;
	}
	
protected:
private:

	// variables
public:
	iPoint initialPosition;
	iPoint objectivePosition;

	Color initialColor;
	Color objectiveColor;

	float age;

	float spawnRate;

	bool isConstant;

	float lifespan;

	// to delete
	int maxParticles;

protected:
private:

	float timeFromLastSpawn;

	SDL_Texture* texture;
	List<Particle*> particles;
};