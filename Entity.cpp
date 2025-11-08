#include "Entity.h"

Entity::Entity(const size_t id, const std::string tag) : m_id(id), m_tag(tag)
{
	m_components = std::make_tuple(CTransform());
}

void Entity::destroy()
{
	m_active = false;
}

bool Entity::isActive() const
{
	return m_active;
}

size_t Entity::getId() const
{
	return m_id;
}

const std::string& Entity::getTag() const
{
	return m_tag;
}
