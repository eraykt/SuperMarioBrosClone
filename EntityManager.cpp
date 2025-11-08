#include "EntityManager.h"

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));

	m_entitiesToAdd.push_back(entity);

	return entity;
}

EntityVec& EntityManager::getEntities()
{
	return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag)
{
	return m_entityMap[tag];
}

const EntityMap& EntityManager::getMap()
{
	return m_entityMap;
}

void EntityManager::removeDeadEntities()
{
	m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(),
		[](const std::shared_ptr<Entity>& e)
		{
			return !e->isActive();
		}),
		m_entities.end()
	);
}

EntityManager::EntityManager() = default;

void EntityManager::update()
{
	for (const auto& e : m_entitiesToAdd)
	{
		m_entities.push_back(e);
		m_entityMap[e->getTag()].push_back(e);
	}

	m_entitiesToAdd.clear();

	removeDeadEntities();
}
