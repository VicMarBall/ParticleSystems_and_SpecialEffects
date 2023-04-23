#include "ParticleSystemManager.h"

#include "App.h"

#include "Textures.h"

ParticleSystemManager::ParticleSystemManager()
{
	name.Create("psmanager");
}

ParticleSystemManager::~ParticleSystemManager()
{
}

bool ParticleSystemManager::Awake()
{
	return true;
}

bool ParticleSystemManager::Start()
{
	firstParticleAvailable = &particlePool[0];

	for (int i = 0; i < PARTICLE_POOL_SIZE - 1; ++i) {
		particlePool[i].SetNext(&particlePool[i + 1]);
	}

	particlePool[PARTICLE_POOL_SIZE - 1].SetNext(NULL);

	alphaTextures[0] = app->tex->Load("Assets/Textures/particles/particle.png");

	alphaTextures[1] = app->tex->Load("Assets/Textures/particles/smoke_white.png");

	alphaTextures[2] = app->tex->Load("Assets/Textures/particles/smoke_shaded.png");


	// adapt it to xml
	/*for (int i = 0; i < ALPHAS_AVAILABLES; ++i) {
		app->tex->Load();
	}*/


	return true;
}

bool ParticleSystemManager::PreUpdate()
{
	return true;
}

bool ParticleSystemManager::Update(float dt)
{
	for (ListItem<ParticleSystem*>* item = particleSystems.start; item != NULL; item = item->next) {
		bool isAlive = item->data->Update(dt);
		if (!isAlive) {
			ParticleSystem* PSToDelete = item->data;
			TakeParticlesFromPS(item->data);
			particleSystems.Del(item);
		}
	}

	return true;
}

bool ParticleSystemManager::PostUpdate()
{
	for (ListItem<ParticleSystem*>* item = particleSystems.start; item != NULL; item = item->next) {
		item->data->PostUpdate();
	}
	return true;
}

ParticleSystem* ParticleSystemManager::CreateParticleSystem(iPoint initialPosition, Blueprint blueprint)
{
	// TODO
	ParticleSystem* PS;

	switch (blueprint)
	{
	case CONSTANT_FIRE:
		// TODO

		break;
	case FIRE:
		// TODO

		break;
	case SMOKE:
		// TODO

		break;
	case EXPLOSION:
		// TODO

		break;
	case NONE:
		break;
	default:
		break;
	}

	particleSystems.Add(PS);

	return PS;
}

void ParticleSystemManager::GiveParticlesToPS(ParticleSystem* particleSystem, int amount)
{
	for (int i = 0; i < amount; ++i) {
		if (firstParticleAvailable != NULL) {
			Particle* newParticle = firstParticleAvailable;

			particleSystem->AssignParticle(newParticle);

			firstParticleAvailable = newParticle->GetNext();
		}
		else {
			// here you can LOG that there are not enough particles
			break;
		}
	}
}

void ParticleSystemManager::TakeParticlesFromPS(ParticleSystem* particleSystem)
{
	List<Particle*> particleList = particleSystem->GetParticleList();
	for (ListItem<Particle*>* item = particleList.start; item != NULL; item = item->next) {
		item->data->SetNext(firstParticleAvailable);
		firstParticleAvailable = item->data;
		particleList.Del(item);
	}
}

bool ParticleSystemManager::CleanUp()
{
	for (int i = 0; i < ALPHAS_AVAILABLES; ++i) {
		app->tex->UnLoad(alphaTextures[i]);
		alphaTextures[i] = nullptr;
	}

	return true;
}
