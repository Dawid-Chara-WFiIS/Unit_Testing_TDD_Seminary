#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>

class Turtle // wrap drawing api to Turtle interface
{
public:
	virtual ~Turtle() = default;
	virtual void penUp() = 0;
	virtual void penDown() = 0;
	virtual void forward(int distance) = 0;
	virtual void turn(int degrees) = 0;
	virtual void goTo(int x, int y) = 0;
	virtual int getX() const = 0;
	virtual int getY() const = 0;
};

class Painter
{
public:
	Painter(Turtle* turtle) : _turtle{ turtle } {}
	void drawCircle()
	{
		_turtle->penUp();
		_turtle->penDown();
		_turtle->penDown();
		_turtle->penDown();
	}
private:
	Turtle* _turtle;
};

class MockTurtle : public Turtle
{
public:
	virtual ~MockTurtle() = default;
	MOCK_METHOD(void, penUp, (), (override));
	MOCK_METHOD(void, penDown, (), (override));
	MOCK_METHOD(void, forward, (int distance), (override));
	MOCK_METHOD(void, turn, (int degrees), (override));
	MOCK_METHOD(void, goTo, (int x, int y), (override));
	MOCK_METHOD(int, getX, (), (const, override));
	MOCK_METHOD(int, getY, (), (const, override));
};

using ::testing::AtLeast;                       

TEST(PainterTest, CanDrawSomething)
{
	auto turtle = std::make_unique<MockTurtle>();                      
	EXPECT_CALL(*turtle, penUp())                  
		.Times(AtLeast(1));

	EXPECT_CALL(*turtle, penDown())
		.Times(AtLeast(3));
	
	auto painter = std::make_unique<Painter>(turtle.get());
	painter->drawCircle();
}