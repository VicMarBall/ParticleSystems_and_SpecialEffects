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

	void SpawnParticle(Particle* p);

	void TurnOff() {
		isConstant = false;
		age = PSLifespan;
	}

protected:
private:

	// variables
public:
	iPoint initialPosition = iPoint{ 100, 100 };
	iPoint objectivePosition = iPoint{ 100, 100 };

	iPoint randomSpawnPositionRangeMin = iPoint{ 0, 0 };
	iPoint randomSpawnPositionRangeMax = iPoint{ 0, 0 };


	Color initialColor = { (unsigned char)255, (unsigned char)0, (unsigned char)0, (unsigned char)255 };
	Color objectiveColor = { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 };

	fPoint shootingVelocity = fPoint{ 0, -10 };

	iPoint randomShootingVelocityRangeMin = iPoint{ -2, 0 };
	iPoint randomShootingVelocityRangeMax = iPoint{ 2, 2 };

	fPoint shootingAcceleration = fPoint{ 0, 1 };

	float age = 0;

	float spawnRate = 1;

	bool isConstant = true;

	float PSLifespan = 10;

	float particleLifespan = 5;

protected:
private:

	float timeFromLastSpawn;

	SDL_Texture* texture;
	List<Particle*> particles;
};