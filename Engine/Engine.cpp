#include "Engine.h"
#include <algorithm>


namespace jc
{
	void Engine::Startup()
	{
		systems.push_back(std::make_unique<Renderer>());
		systems.push_back(std::make_unique<EventSystem>());
		systems.push_back(std::make_unique<ResourceSystem>());
		systems.push_back(std::make_unique<InputSystem>());
		systems.push_back(std::make_unique<AudioSystem>());


		std::for_each(systems.begin(), systems.end(), [](auto& system) {system->Startup(); });
		
		REDISTER_CLASS(Actor)
		REDISTER_CLASS(CameraComponent)
		REDISTER_CLASS(MeshComponent)
		REDISTER_CLASS(physicsComponent)
		REDISTER_CLASS(AudioComponent)
		REDISTER_CLASS(FreeCameraController)
		REDISTER_CLASS(ModelComponent)
		REDISTER_CLASS(LightComponent)


	}

	void Engine::Shutdown()
	{
		std::for_each(systems.begin(), systems.end(), [](auto& system) {system->Shutdown(); });

		
	}
	void Engine::Update()
	{
		time.Tick();
		std::for_each(systems.begin(), systems.end(), [this](auto& system) {system->Update(this->time.deltaTime); });
	}
	void Engine::Draw(Renderer* renderer)
	{
		std::for_each(systems.begin(), systems.end(), [renderer](auto& system) {if(dynamic_cast<GraphicsSystem*>(system.get())) dynamic_cast<GraphicsSystem*>(system.get())->Draw(renderer); });

	}
}