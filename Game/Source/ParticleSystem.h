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
		float spawnRate, float lifespan, bool isConstant);

	void SetObjective(int x, int y);

	void Start();
	bool Update(float dt);
	void PostUpdate();

	void CleanParticles();

	void AssignParticle(Particle* particle);

	List<Particle*> GetParticleList() const {
		return particles;
	}
	
	void SetTexture(SDL_Texture* tex) {
		texture = tex;
	}

protected:
private:

	// variables
public:
	iPoint initialPosition = iPoint{ 100, 100 };
	iPoint objectivePosition = iPoint{ 200, 100 };

	Color initialColor = { (char)255, (char)255, (char)255, (char)255 };
	Color objectiveColor = { (char)255, (char)255, (char)255, (char)0 };

	fPoint shootingVelocity = fPoint{ 0, 10 };
	fPoint shootingAcceleration = fPoint{ 0, -2 };

	float age = 0;

	float spawnRate = 1;

	bool isConstant = false;

	float PSLifespan = 10;

	float particleLifespan = 5;

protected:
private:

	float timeFromLastSpawn;

	SDL_Texture* texture;
	List<Particle*> particles;
};