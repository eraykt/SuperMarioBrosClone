#pragma once

#include <string>
#include <tuple>
#include "Components.h"

typedef std::tuple<
	CTransform> ComponentTuple;

class Entity
{
private:
	friend class EntityManager;

	bool m_active;
	const size_t m_id;
	const std::string m_tag;

	ComponentTuple m_components;

	Entity(const size_t id, const std::string tag);

public:

	void destroy();
	bool isActive() const;
	size_t getId() const;
	const std::string& getTag() const;

	template<class T>
	bool hasComponent() const
	{
		return getComponent<T>().has;
	}

	template<class T, typename... TArgs>
	T& addComponent(TArgs &&... mArgs)
	{
		auto& component = getComponent<T>();
		component = T(std::forward<TArgs>(mArgs)...);
		component.has = true;
		return component;
	}

	template<class T>
	T& getComponent()
	{
		return std::get<T>(m_components);
	}

	template<class T>
	const T& getComponent() const
	{
		return std::get<T>(m_components);
	}

	template<class T>
	void removeComponent() const
	{
		getComponent<T>() = T();
	}
};

