#include "ParticleSystemManager.h"

ParticleSystemManager::ParticleSystemManager()
{
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
		}
	}

	return true;
}

bool ParticleSystemManager::PostUpdate()
{
	return true;
}

ParticleSystem* ParticleSystemManager::CreateParticleSystem(Blueprint blueprint)
{
	ParticleSystem* PS = new ParticleSystem();
	PS->initialPosition = iPoint{ 100, 100 };

	switch (blueprint)
	{
	case FIRE:
		GiveParticlesToPS(PS, 20);
		PS->initialColor.r = 255;
		break;
	case SMOKE:
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
			firstParticleAvailable = newParticle->GetNext();

			particleSystem->AssignParticle(newParticle);
		}
		else {
			// here you can LOG that there are not enough particles
		}
	}
}

void ParticleSystemManager::TakeParticlesFromPS(ParticleSystem* particleSystem)
{
	for (ListItem<Particle*>* item = particleSystem->GetParticleList().start; item != NULL; item = item->next) {
		item->data->SetNext(firstParticleAvailable);
		firstParticleAvailable = item->data;
	}

	particleSystem->CleanParticles();

}

bool ParticleSystemManager::CleanUp()
{
	return true;
}
