#include "Entity.h"
#include "gtest/gtest.h"

#include <memory>

class EntityTest : public ::testing::Test
{
protected:
	EntityTest()
	{
		_first = std::make_unique< Entity >("Player_1", 100, 20);
		_second = std::make_unique< Entity >("Player_2", 120, 10);
	}
	void SetUp() override
	{
		_first->setHealthPoints(100);
		_second->setHealthPoints(120);
	}

	std::unique_ptr<Entity> _first;
	std::unique_ptr<Entity> _second;

};

TEST_F(EntityTest, HitOnceTest)
{
	_first->hit(_second.get());
	EXPECT_EQ(_second->getHealthPoints(), 100);
	EXPECT_EQ(_first->getHealthPoints(), 100);
}

TEST_F(EntityTest, HitUntilDeadTest)
{
	while (_first->hit(_second.get()));
	EXPECT_LE(_second->getHealthPoints(), 0);
	EXPECT_LE(_second->getHealthPoints(), 0);
}