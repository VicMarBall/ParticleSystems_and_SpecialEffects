#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"
#include "ParticleSystemManager.h"


#include "Defs.h"
#include "Log.h"

Scene::Scene() : Module()
{
	name.Create("scene");
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene::Start()
{
	return true;
}

// Called each loop iteration
bool Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene::Update(float dt)
{
	if(app->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		app->render->camera.y -= 1;

	if(app->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		app->render->camera.y += 1;

	if(app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		app->render->camera.x -= 1;

	if(app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		app->render->camera.x += 1;


	if (app->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN) {
		if (smokePS == nullptr) {
			smokePS = app->PSManager->CreateParticleSystem(iPoint{200, 200}, Blueprint::SMOKE);
		}
		else {
			smokePS->TurnOff();
			smokePS = nullptr;
		}
	}

	if (app->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN) {
		iPoint startPosition = iPoint{ 200, 300 };
		ParticleSystem* ps = app->PSManager->CreateParticleSystem(startPosition, FIRE);
		iPoint endPosition = iPoint{ 600, 300 };
		ps->SetObjective(endPosition.x, endPosition.y);
	}

	if (app->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN) {
		if (mouseFirePS == nullptr) {
			mouseFirePS = app->PSManager->CreateParticleSystem(iPoint{ 100, 100 }, Blueprint::CONSTANT_FIRE);
		}
		else {
			mouseFirePS->TurnOff();
			mouseFirePS = nullptr;
		}
	}
	
	if (app->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN) {
		iPoint mousePos;
		app->input->GetMousePosition(mousePos.x, mousePos.y);
		app->PSManager->CreateParticleSystem(mousePos, EXPLOSION);
	}

	if (mouseFirePS != nullptr) {
		iPoint mousePos;
		app->input->GetMousePosition(mousePos.x, mousePos.y);
		mouseFirePS->SetPosition(mousePos.x, mousePos.y);
	}

	return true;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;

	if(app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
