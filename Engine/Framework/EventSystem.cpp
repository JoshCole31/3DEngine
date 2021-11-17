#include "EventSystem.h"
#include "Object/Object.h"

namespace jc{
	void EventSystem::Startup()
	{
	}

	void EventSystem::Shutdown()
	{
	}

	void EventSystem::Update(float dt)
	{
	}

	void EventSystem::Subcribe(const std::string& name, function_t function,Object* receiver)
	{
		Observer observer;
		observer.function = function;
		observer.receiver = receiver;

		observers[name].push_back(observer);
	}

	void EventSystem::Notify(const Event& event)
	{
		auto& ebentObservers = observers[event.name];
		for (auto& observer : ebentObservers)
		{
			if (event.receiver == nullptr || event.receiver == observer.receiver)
			{
				observer.function(event);
			}
		}
	}
	void EventSystem::Unsubscribe(const std::string& name, Object* receiver)
	{
		auto& eventObservers = observers[name];
		for (auto iter = eventObservers.begin(); iter != eventObservers.end();)
		{
			if (iter->receiver == receiver)
			{
				iter = eventObservers.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
}