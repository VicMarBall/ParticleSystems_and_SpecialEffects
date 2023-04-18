#pragma once
#ifndef __PARTICLESYSTEMMANAGER_H__
#define __PARTICLESYSTEMMANAGER_H__

#include "Module.h"
#include "List.h"
#include "ParticleSystem.h"

#define PARTICLE_POOL_SIZE 200

#define ALPHAS_AVAILABLES 1

enum Blueprint {
	FIRE,
	SMOKE,
	NONE
};

enum AlphasIDs {
	BASIC = 0

};

class SDL_Texture;

// an object pool for particles and a manager for particle systems

class ParticleSystemManager : public Module
{
public:

	ParticleSystemManager();

	// Destructor
	virtual ~ParticleSystemManager();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();


	ParticleSystem* CreateParticleSystem(Blueprint blueprint);


	void GiveParticlesToPS(ParticleSystem* particleSystem, int amount);

	void TakeParticlesFromPS(ParticleSystem* particleSystem);





	// Called before quitting
	bool CleanUp();

private:
	List<ParticleSystem*> particleSystems;
	Particle particlePool[PARTICLE_POOL_SIZE];
	Particle* firstParticleAvailable;

	SDL_Texture* alphaTextures[ALPHAS_AVAILABLES];

};

#endif // __SCENE_H__