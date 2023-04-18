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
	float spawnRate, float lifespan, bool isConstant)
{
	/*this->position = position;
	this->velocity = velocity;
	this->acceleration = acceleration;
	this->initialR = initialR;
	this->initialG = initialG;
	this->initialB = initialB;
	this->initialAlpha = initialAlpha;*/
	this->spawnRate = spawnRate;
	this->PSLifespan = lifespan;
	this->isConstant = isConstant;

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
	timeFromLastSpawn += dt;

	for (ListItem<Particle*>* item = particles.start; item != nullptr; item = item->next) {
		if (item->data != nullptr) {
			if (item->data->IsBeingUsed()) {
				item->data->Update(dt);
			}
			else {
				if (spawnRate <= timeFromLastSpawn) {
					SpawnParticle(item->data);
					timeFromLastSpawn -= spawnRate;
				}
			}
		}
	}

	age += dt;

	return (age < PSLifespan || isConstant);
}

void ParticleSystem::PostUpdate()
{
	for (ListItem<Particle*>* item = particles.start; item != nullptr; item = item->next) {
		if (item->data != nullptr) {
			if (item->data->IsBeingUsed()) {
				app->render->DrawParticleAlpha(texture, item->data->GetPosition().x, item->data->GetPosition().y,
					item->data->GetColor().r, item->data->GetColor().g, item->data->GetColor().b, item->data->GetColor().a);
			}
		}
	}
}

void ParticleSystem::CleanParticles()
{
	particles.Clear();
}

void ParticleSystem::AssignParticle(Particle* particle)
{
	particle->ResetParticle();
	particles.Add(particle);
}

void ParticleSystem::SpawnParticle(Particle* p)
{
	float t = age / PSLifespan;

	fPoint position;
	// lerp
	position.x = initialPosition.x + (int)(t * (float)(objectivePosition.x - initialPosition.x));
	position.y = initialPosition.y + (int)(t * (float)(objectivePosition.y - initialPosition.y));

	if (randomSpawnPositionRangeMin.x - randomSpawnPositionRangeMax.x != 0) {
		position.x += (rand() % (randomSpawnPositionRangeMin.x - randomSpawnPositionRangeMax.x)) - randomSpawnPositionRangeMin.x;

	}

	if (randomSpawnPositionRangeMin.y - randomSpawnPositionRangeMax.y != 0) {
		position.y += (rand() % (randomSpawnPositionRangeMin.y - randomSpawnPositionRangeMax.y)) - randomSpawnPositionRangeMin.y;

	}

	fPoint velocity = shootingVelocity;

	if (randomShootingVelocityRangeMin.x - randomShootingVelocityRangeMax.x != 0) {
		velocity.x += (rand() % (randomShootingVelocityRangeMin.x - randomShootingVelocityRangeMax.x)) - randomShootingVelocityRangeMin.x;

	}

	if (randomShootingVelocityRangeMin.y - randomShootingVelocityRangeMax.y != 0) {
		velocity.y += (rand() % (randomShootingVelocityRangeMin.y - randomShootingVelocityRangeMax.y)) - randomShootingVelocityRangeMin.y;

	}

	p->Initialize(position, velocity, shootingAcceleration, initialColor.r, initialColor.g, initialColor.b, initialColor.a, particleLifespan);
}
