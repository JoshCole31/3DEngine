#pragma once
#include "Object.h"
#include "Core/Serializable.h"
#define NOMINMAX
#include <list>
#include <memory>
#include <vector>

namespace jc
{
	class Actor;
	class Engine;
	//class Renderer;

	
	class Scene : public Object,public ISerializable
	{
	public:
		void Update(float dt);
		void Draw(class Renderer* renderer); //can do the class here 

		void Addactor(std::unique_ptr<Actor> actor);
		void RemoveActor(Actor* actor);
		void RemoveAllActors();

		Actor* FindActor(const std::string& name);

		template<typename T>
		T* GetActor();

		template<typename T>
		std::vector<T*> GetActors();

		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	public:
		Engine* engine{nullptr};

	private:
		std::vector<std::unique_ptr<Actor>> actors;
		std::vector<std::unique_ptr<Actor>> newActors;

	};

	template<typename T>
	inline T* Scene::GetActor()
	{
		for (auto& actor : actors)
		{
			if (dynamic_cast<T*>(actor.get())) return dynamic_cast<T*>(actor.get());
		}

		return nullptr;
	}


	template<typename T>
	inline std::vector<T*> Scene::GetActors()
	{
		std::vector<T*>result;

		for (auto & actor : actors)
		{
			if (dynamic_cast<T*>(actor.get())) result.push_back (dynamic_cast<T*>(actor.get()));
		}
		return result;
	}
}