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
	/*this->position = position;
	this->velocity = velocity;
	this->acceleration = acceleration;
	this->initialR = initialR;
	this->initialG = initialG;
	this->initialB = initialB;
	this->initialAlpha = initialAlpha;*/
	this->spawnRate = spawnRate;
	this->lifespan = lifespan;
	this->isConstant = isConstant;
	this->maxParticles = maxParticles;

	age = 0;
}

void ParticleSystem::SetObjective(int x, int y)
{
	objectivePosition.x = x;
	objectivePosition.y = y;
}

void ParticleSystem::Start()
{

}

bool ParticleSystem::Update(float dt)
{
	for (ListItem<Particle*>* item = particles.start; item != NULL; item = item->next) {
		if (item->data->IsBeingUsed()) {
			item->data->Update(dt);
		}
	}

	age += dt;

	return (age > lifespan);
}

void ParticleSystem::PostUpdate()
{
	float t = age / lifespan;

	iPoint position;
	// lerp
	position.x = initialPosition.x + (int)(t * (float)(objectivePosition.x - initialPosition.x));
	position.y = initialPosition.y + (int)(t * (float)(objectivePosition.y - initialPosition.y));


	for (ListItem<Particle*>* item = particles.start; item != NULL; item = item->next) {
		if (item->data->IsBeingUsed()) {
			app->render->DrawParticleAlpha(texture, position.x + item->data->GetPosition().x, position.y + item->data->GetPosition().y, 
				item->data->GetColor().r, item->data->GetColor().g, item->data->GetColor().b, item->data->GetColor().a);
		}
	}
}

void ParticleSystem::CleanParticles()
{
	particles.Clear();
}

void ParticleSystem::AssignParticle(Particle* particle)
{
	particles.Add(particle);
}
