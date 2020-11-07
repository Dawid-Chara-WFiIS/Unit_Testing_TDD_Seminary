#include "Entity.h"

std::string Entity::getName() const
{
	return _name;
}

int Entity::getHealthPoints() const
{
	return _healthPoints;
}

int Entity::getAttackDamagePoints() const
{
	return _attackDamagePoints;
}

void Entity::setName(const std::string name)
{
	_name = name;
}

void Entity::setHealthPoints(int healthPoints)
{
	_healthPoints = healthPoints;
}

void Entity::setAttackDamagePoints(int attackDamagePoints)
{
	_attackDamagePoints = attackDamagePoints;
}

bool Entity::hit(Entity* other)
{
	if (other->getHealthPoints() <= 0)
		return false; // already dead entity

	const auto currentHealthPoints = other->getHealthPoints();
	other->setHealthPoints(currentHealthPoints - getAttackDamagePoints());
	return true;
}