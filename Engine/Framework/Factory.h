#pragma once
#include <memory>
#include <map>

namespace jc
{
	template<class TBase>
	class Creatorbase
	{
	public:
		virtual std::unique_ptr<TBase> Create()const = 0;
	};

	template <class T,class TBase>
	class Creator : public Creatorbase<TBase>
	{
		public:
		std::unique_ptr<TBase> Create()const override
		{
			return std::make_unique<T>();
		}
	};

	template<class TKey, class TBase>
	class Factory
	{
	public:
		template<class T= TBase>
		std::unique_ptr<T>Create(TKey key);

		template<class T>
		void Register(TKey key);

		template<class T>
		void RegisterPrototype(TKey key, std::unique_ptr<TBase> instance);

	protected:
		std::map <TKey, std::unique_ptr<Creatorbase<TBase>>> registry;
	};


	template<class TKey, class TBase>
	template<class T>
	inline std::unique_ptr<T> Factory<TKey, TBase>::Create(TKey key)
	{
		auto iter = registry.find(key);
		if (iter != registry.end())
		{
			return std::unique_ptr<T>(dynamic_cast<T*>(iter->second->Create().release()));
		}
		return std::unique_ptr<T>();
	}

	template<class TKey, class TBase>
	template<class T>
	inline void Factory<TKey, TBase>::Register(TKey key)
	{
		registry[key] = std::make_unique<Creator<T, TBase>>();
	}


	template <class TBase>
	class Prototype : public Creatorbase<TBase>
	{
	public:
		Prototype(std::unique_ptr<TBase> instance) : instance { std::move(instance) }{}
		std::unique_ptr<TBase> Create()const override
		{
			return instance->Clone();
		}

	private:
		std::unique_ptr<TBase> instance;
	};

	template<class TKey, class TBase>
	template<class T>
	inline void Factory<TKey, TBase>::RegisterPrototype(TKey key, std::unique_ptr<TBase> instance)
	{
		registry[key] = std::make_unique<Prototype<TBase>>(std::move(instance));
	}
}