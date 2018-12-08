#include "gtest/gtest.h"
#include "../Datastrukturer/Stack.h"
#include <exception>

class StackTest : public testing::Test
{
protected:
	const unsigned int capacity = 5;
	
	Stack<int>* stackWithInts;
	Stack<float>* stackWithFloats;
	
	virtual void SetUp()
	{
		stackWithInts = new Stack<int>(capacity);
		stackWithFloats = new Stack<float>(capacity);
	}
	
	virtual void TearDown()
	{
		delete stackWithInts;
		delete stackWithFloats;
	}

	virtual void FillStackWithInts()
	{
		for (int i = 0; i < capacity; i++)
		{
			stackWithInts->Push(i);
		}
	}
};


TEST_F(StackTest, StackWithFloatsShouldReturnFloats)
{
	stackWithFloats->Push(1.0f);
	stackWithFloats->Push(2.0f);

	EXPECT_EQ(2.0f, stackWithFloats->Pop());
}


TEST_F(StackTest, WhenStackIsNotEmptyItShouldReturnNotEmpty)
{
	stackWithInts->Push(1);

	EXPECT_EQ(false, stackWithInts->IsEmpty());
}


TEST_F(StackTest, WhenStackIsEmptyItShouldReturnEmpty)
{
	EXPECT_EQ(true, stackWithInts->IsEmpty());
}


TEST_F(StackTest, WhenStackIsNotFullItShouldReturnNotFull)
{
	EXPECT_EQ(false, stackWithInts->IsFull());
}


TEST_F(StackTest, WhenStackIsFullItShouldReturnFull)
{
	FillStackWithInts();

	EXPECT_EQ(true, stackWithInts->IsFull());
}


TEST_F(StackTest, WhenStackIsEmptyPopShouldThrowException)
{
	EXPECT_THROW(stackWithInts->Pop(), std::underflow_error);
}


TEST_F(StackTest, WhenStackIsFullPushShouldThrowException)
{
	FillStackWithInts();

	EXPECT_THROW(stackWithInts->Push(1), std::overflow_error);
}


TEST_F(StackTest, WhenPopStackShouldReturnLastPushedItem)
{
	stackWithInts->Push(54);
	stackWithInts->Push(12);

	EXPECT_EQ(12, stackWithInts->Pop());
}


TEST_F(StackTest, WhenPeekStackShouldReturnLastPushedItem)
{
	stackWithInts->Push(54);
	stackWithInts->Push(12);

	EXPECT_EQ(12, stackWithInts->Peek());
}


TEST_F(StackTest, WhenPeekStackShouldNotRemoveLastPushedItem)
{
	stackWithInts->Push(54);
	stackWithInts->Push(12);
	stackWithInts->Peek();

	EXPECT_EQ(12, stackWithInts->Pop());
}
