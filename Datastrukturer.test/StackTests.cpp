#include "gtest/gtest.h"
#include "../Datastrukturer/Stack.h"
#include <exception>
#include <string>
#include <vector>

class StackTest : public testing::Test
{
protected:
	const unsigned int capacity = 5;
	
	Stack<int>* stackWithInts;
	Stack<float>* stackWithFloats;
	Stack<std::string>* stackWithStrings;
	Stack<std::vector<int>>* stackWithVectors;
	
	virtual void SetUp()
	{
		stackWithInts = new Stack<int>(capacity);
		stackWithFloats = new Stack<float>(capacity);
		stackWithStrings = new Stack<std::string>(capacity);
		stackWithVectors = new Stack<std::vector<int>>(capacity);
	}
	
	virtual void TearDown()
	{
		delete stackWithInts;
		delete stackWithFloats;
		delete stackWithStrings;
		delete stackWithVectors;
	}
	
	virtual void FillStackWithInts()
	{
		for (int i = 0; i < capacity; i++)
		{
			stackWithInts->Push(i);
		}
	}
	
};


TEST_F(StackTest, StackWithStringsShouldReturnStrings)
{
	std::string testString1 = "Testing testing";
	std::string testString2 = "Hello World!";

	stackWithStrings->Push(testString1);
	stackWithStrings->Push(testString2);

	EXPECT_EQ(testString2, stackWithStrings->Pop());
}


TEST_F(StackTest, StackWithVectorsShouldReturnVectors)
{
	std::vector<int> testVector1;
	testVector1.push_back(8);
	testVector1.push_back(1);
	stackWithVectors->Push(testVector1);

	std::vector<int> testVector2;
	testVector2.push_back(2);
	testVector2.push_back(5);
	stackWithVectors->Push(testVector2);

	EXPECT_EQ(testVector2, stackWithVectors->Pop());
}


TEST_F(StackTest, StackWithFloatsShouldReturnFloats)
{
	stackWithFloats->Push(1.0f);
	stackWithFloats->Push(2.0f);

	EXPECT_EQ(2.0f, stackWithFloats->Pop());
}


TEST_F(StackTest, WhenStackIsNotEmptyItShouldReturnNotEmpty)
{
	stackWithInts->Push(1);

	EXPECT_FALSE(stackWithInts->IsEmpty());
}


TEST_F(StackTest, WhenStackIsEmptyItShouldReturnEmpty)
{
	EXPECT_TRUE(stackWithInts->IsEmpty());
}


TEST_F(StackTest, WhenStackIsNotFullItShouldReturnNotFull)
{
	EXPECT_FALSE(stackWithInts->IsFull());
}


TEST_F(StackTest, WhenStackIsFullItShouldReturnFull)
{
	FillStackWithInts();

	EXPECT_TRUE(stackWithInts->IsFull());
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
