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
		Entity(name, healthPoints, attackDamagePoints), _id { id }
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
	bool addRecord(const EntityRecord& recordToAdd)
	{
		const auto foundSameId = std::find_if(_container.begin(), _container.end(), [recordToAdd](const auto& record) { return record.getId() == recordToAdd.getId(); });
		const auto foundSameName = std::find_if(_container.begin(), _container.end(), [recordToAdd](const auto& record) { return record.getName().compare(recordToAdd.getName()) == 0; });
		if (foundSameId != _container.end() || foundSameName != _container.end())
			return false;

		_container.push_back(recordToAdd);
		return true;
	}
	void clear()
	{
		_container.clear();
	}

private:
	std::vector<EntityRecord> _container;
};

// ---- test area
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
		_database->addRecord({ 1, "Player1", 120, 20 });
	}

	std::unique_ptr<EntityDatabase> _database;
};

TEST_F(EntityDatabaseTest, AddRecordWithExistingIdButWithUniqueNameToDatabaseTest)
{
	const auto recordAdded = _database->addRecord({ 1, "Player2", 120, 20 });
	EXPECT_FALSE(recordAdded);
}

TEST_F(EntityDatabaseTest, AddRecordWithExistingIdAndWithExistingNameToDatabaseTest)
{
	const auto recordAdded = _database->addRecord({ 1, "Player1", 120, 20 });
	EXPECT_FALSE(recordAdded);
}

TEST_F(EntityDatabaseTest, AddRecordWithUniqueIdAndWithUniqueNameToDatabaseTest)
{
	const auto recordAdded = _database->addRecord({ 2, "Player2", 120, 20 });
	EXPECT_TRUE(recordAdded);
}