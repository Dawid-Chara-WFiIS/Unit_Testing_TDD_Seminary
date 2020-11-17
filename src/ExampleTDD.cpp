#include "Entity.h"
#include "gtest/gtest.h"

#include <memory>
#include <string>
#include <vector>
#include <algorithm>

class EntityRecord : public Entity
{
public:
	EntityRecord(int id, const std::string& name, int healthPoints, int attackDamagePoints) :
		Entity(name, healthPoints, attackDamagePoints), _id{ id }
	{
	}
	[[nodiscard]] int getId() const
	{
		return _id;
	}
	void setId(int newId)
	{
		_id = newId;
	}

private:
	int _id;
};

class EntityDatabase
{
public:
	void addRecord(const EntityRecord& recordToAdd)
	{
		_container.push_back(recordToAdd);
	}
	[[nodiscard]] unsigned getNumberOfRecords() const
	{
		return _container.size();
	}
	void clear()
	{
		_container.clear();
	}


private:
	std::vector<EntityRecord> _container;
};

class EntityDatabaseTest : public ::testing::Test
{
protected:
	EntityDatabaseTest()
	{
		_database = std::make_unique<EntityDatabase>();
	}

	void SetUp() override
	{
		_database->clear();
	}

	std::unique_ptr<EntityDatabase> _database;
};

/* pre-requirement
- method that checks if record is unique by id
- method that checks if record is unique name
- addRecord method with validation if record to add is unique by name and id
*/
TEST_F(EntityDatabaseTest, GetInintialNumberOfRecordsInDatabaseTest)
{
	const auto numberOfRecords = _database->getNumberOfRecords();
	EXPECT_EQ(numberOfRecords, 0);
}

TEST_F(EntityDatabaseTest, AddRecordTest)
{
	const auto numberOfRecordsPre = _database->getNumberOfRecords();
	_database->addRecord({ 1, "Player1", 120, 20 });
	const auto numberOfRecordsAfter = _database->getNumberOfRecords();
	EXPECT_EQ(numberOfRecordsPre + 1, numberOfRecordsAfter);
}

TEST_F(EntityDatabaseTest, ClearDatabaseTest)
{
	_database->addRecord({ 1, "Player1", 120, 20 });
	_database->addRecord({ 2, "Player2", 120, 20 });
	_database->addRecord({ 3, "Player3", 120, 20 });
	_database->clear();
	const auto numberOfRecordsAfterClear = _database->getNumberOfRecords();
	EXPECT_EQ(numberOfRecordsAfterClear, 0);
}
