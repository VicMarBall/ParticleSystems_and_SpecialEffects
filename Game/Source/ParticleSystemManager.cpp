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
	ParticleSystem* PS = new ParticleSystem();
	PS->initialPosition = initialPosition;

	switch (blueprint)
	{
	case FIRE:
		
		break;
	case SMOKE:
		GiveParticlesToPS(PS, 50);
		PS->SetTexture(alphaTextures[SMOKE_SHADED]);
		PS->spawnRate = 0.3f;
		PS->isConstant = true;
		PS->initialColor.Set(100, 100, 100, 255);
		PS->objectiveColor.Set(250, 250, 150, 0);
		PS->particleLifespan = 10;
		PS->shootingAcceleration = fPoint{ 0.0f, 0.5f };
		PS->randomSpawnPositionRangeMin = iPoint{ -20, 0 };
		PS->randomSpawnPositionRangeMax = iPoint{ 20, 0 };
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
