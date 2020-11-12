#pragma once
#include <string>

class Entity
{
public:
	Entity(const std::string& name, int healthPoints, int attackDamagePoints) :
		_name{ name },
		_healthPoints{ healthPoints }, 
		_attackDamagePoints{ attackDamagePoints }
	{
	}

	[[nodiscard]] std::string getName() const;
	[[nodiscard]] int getHealthPoints() const;
	[[nodiscard]] int getAttackDamagePoints() const;
	[[nodiscard]] std::string getStringRepr() const;

	void setName(const std::string name);
	void setHealthPoints(int healthPoints);
	void setAttackDamagePoints(int attackDamagePoints);

	bool hit(Entity* other);
	
private:
	std::string _name;
	int _healthPoints;
	int _attackDamagePoints;
	
};

