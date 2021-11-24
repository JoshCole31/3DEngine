#pragma once

#define REDISTER_CLASS(class) jc::ObjectFactory::Instance().Register<class>(#class);

//systems

//core
#include "Core/Utilites.h"
#include"Core/FileSystem.h"
#include "Core/Timer.h"
#include "Core/Json.h"
#include "Core/Serializable.h"

//Framework
#include "Framework/EventSystem.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"

//math

#include "Math/MathUtils.h"
#include "Math/Transform.h"
#include "Math/Random.h"

//Object
#include "Object/Actor.h"
#include "Object/Scene.h"

//components
#include "Component/CameraComponent.h"
#include "Component/AudioComponent.h"
#include "Component/GraphicsComponent.h"
#include "Component/MeshComponent.h"
#include "Component/physicsComponent.h"

#include<vector>
#include<memory>
#include<algorithm>

//Resource

//graphics
#include"Graphics/Renderer.h"
#include"Graphics/Texture.h"
#include"Graphics/Material.h"
#include"Graphics/Program.h"
#include"Graphics/Renderer.h"
#include"Graphics/Shader.h"

#include"Graphics/VertexBuffer.h"
#include"Graphics/VertexIndexBuffer.h"



#include "Resource/ResourceSystem.h"
#include "Input/InputSystem.h"

#include "Audio/AudioSystem.h"


namespace jc
{
	using ObjectFactory = Singleton<Factory<std::string, Object>>;
	

	class Engine
	{
	public:
		void Startup();
		void Shutdown();
		
		void Update();
		void Draw(Renderer* renderer);

		template<typename T>
		T* Get();

	public:
		FrameTimer time;

	private:
		std::vector<std::unique_ptr<System>> systems;

	};
	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems)
		{
			if(dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}
		return nullptr;
	}
}