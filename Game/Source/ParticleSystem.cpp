#include "ParticleSystem.h"

#include "App.h"

#include "Render.h"

ParticleSystem::ParticleSystem()
{
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::SetParticleSystem(iPoint position, iPoint velocity, iPoint acceleration,
	char initialR, char initialG, char initialB, char initialAlpha,
	float spawnRate, float lifespan, bool isConstant, int maxParticles)
{
	this->position = position;
	this->velocity = velocity;
	this->acceleration = acceleration;
	this->initialR = initialR;
	this->initialG = initialG;
	this->initialB = initialB;
	this->initialAlpha = initialAlpha;
	this->spawnRate = spawnRate;
	this->lifespan = lifespan;
	this->isConstant = isConstant;
	this->maxParticles = maxParticles;
}

void ParticleSystem::Start()
{
	// to delete
	for (int i = 0; i < maxParticles; ++i)
	{
		Particle* p = new Particle;
		particles.Add(p);
	}
}

void ParticleSystem::Update(float dt)
{
	for (ListItem<Particle*>* item = particles.start; item != NULL; item = item->next) {
		if (item->data->IsBeingUsed()) {
			item->data->Update(dt);
		}
	}
}

void ParticleSystem::PostUpdate()
{
	for (ListItem<Particle*>* item = particles.start; item != NULL; item = item->next) {
		if (item->data->IsBeingUsed()) {
			app->render->DrawParticleAlpha(texture, position.x + item->data->position.x, position.y + item->data->position.y, 
				item->data->r, item->data->g, item->data->b, item->data->alpha);
		}
	}
}
