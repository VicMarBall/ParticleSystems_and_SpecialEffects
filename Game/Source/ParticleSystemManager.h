#pragma once
#ifndef __PARTICLESYSTEMMANAGER_H__
#define __PARTICLESYSTEMMANAGER_H__

#include "Module.h"
#include "List.h"
#include "ParticleSystem.h"

// an object pool for particles and a manager for particle systems
	// 
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

	// Called before quitting
	bool CleanUp();

private:
	List<ParticleSystem*> particleSystems;

};

#endif // __SCENE_H__