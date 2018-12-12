#include "gtest/gtest.h"
#include "../Datastrukturer/Queue.h"
#include <exception>
#include <string>
#include <vector>

class QueueTest : public testing::Test
{
protected:
	const unsigned int capacity = 5;

	Queue<int>* queueWithInts;
	Queue<float>* queueWithFloats;
	Queue<std::string>* queueWithStrings;
	Queue<std::vector<int>>* queueWithVectors;

	virtual void SetUp()
	{
		queueWithInts = new Queue<int>(capacity);
		queueWithFloats = new Queue<float>(capacity);
		queueWithStrings = new Queue<std::string>(capacity);
		queueWithVectors = new Queue<std::vector<int>>(capacity);
	}

	virtual void TearDown()
	{
		delete queueWithInts;
		delete queueWithFloats;
		delete queueWithStrings;
		delete queueWithVectors;
	}

	virtual void FillQueueWithInts()
	{
		for (int i = 0; i < capacity; i++)
		{
			queueWithInts->PushBack(i);
		}
	}
};


TEST_F(QueueTest, QueueWithStringsShouldReturnStrings)
{
	std::string testString1 = "Testing testing";
	std::string testString2 = "Hello World!";

	queueWithStrings->PushBack(testString1);
	queueWithStrings->PushBack(testString2);

	EXPECT_EQ(testString1, queueWithStrings->PopFront());
}


TEST_F(QueueTest, QueueWithVectorsShouldReturnVectors)
{
	std::vector<int> testVector1;
	testVector1.push_back(8);
	testVector1.push_back(1);
	queueWithVectors->PushBack(testVector1);

	std::vector<int> testVector2;
	testVector2.push_back(2);
	testVector2.push_back(5);
	queueWithVectors->PushBack(testVector2);

	EXPECT_EQ(testVector1, queueWithVectors->PopFront());
}


TEST_F(QueueTest, QueueWithFloatsShouldReturnFloats)
{
	queueWithFloats->PushBack(1.0f);
	queueWithFloats->PushBack(2.0f);

	EXPECT_EQ(1.0f, queueWithFloats->PopFront());
}


TEST_F(QueueTest, WhenQueueIsNotEmptyItShouldReturnNotEmpty)
{
	queueWithInts->PushBack(1);

	EXPECT_FALSE(queueWithInts->IsEmpty());
}


TEST_F(QueueTest, WhenQueueIsEmptyItShouldReturnEmpty)
{
	EXPECT_TRUE(queueWithInts->IsEmpty());
}



TEST_F(QueueTest, WhenQueueIsNotEmptyAndNotFullItShouldReturnNotFull)
{
	queueWithInts->PushBack(1);

	EXPECT_FALSE(queueWithInts->IsFull());
}


TEST_F(QueueTest, WhenQueueIsFullItShouldReturnIsFull)
{
	FillQueueWithInts();

	EXPECT_TRUE(queueWithInts->IsFull());
}


TEST_F(QueueTest, WhenQueueIsEmptyPopFrontShouldThrowException)
{
	EXPECT_THROW(queueWithInts->PopFront(), std::underflow_error);
}


TEST_F(QueueTest, WhenQueueIsFullPushBackShouldThrowException)
{
	FillQueueWithInts();

	EXPECT_THROW(queueWithInts->PushBack(1), std::overflow_error);
}


TEST_F(QueueTest, WhenPopFrontQueueShouldReturnFirstPushBackedItem)
{
	queueWithInts->PushBack(54);
	queueWithInts->PushBack(12);

	EXPECT_EQ(54, queueWithInts->PopFront());
}


TEST_F(QueueTest, WhenPeekQueueShouldReturnFirstPushBackedItem)
{
	queueWithInts->PushBack(54);
	queueWithInts->PushBack(12);

	EXPECT_EQ(54, queueWithInts->Peek());
}


TEST_F(QueueTest, WhenPeekQueueShouldNotRemoveFirstPushBackedItem)
{
	queueWithInts->PushBack(54);
	queueWithInts->PushBack(12);
	queueWithInts->Peek();

	EXPECT_EQ(54, queueWithInts->PopFront());
}


TEST_F(QueueTest, WhenQueueIsEmptySizeShouldReturnZero)
{
	EXPECT_EQ(0, queueWithInts->Size());
}


TEST_F(QueueTest, WhenQueueIsFullSizeShouldReturnCapacity)
{
	FillQueueWithInts();

	EXPECT_EQ(capacity, queueWithInts->Size());
}


TEST_F(QueueTest, WhenQueueHasTwoItemsSizeShouldReturnTwo)
{
	queueWithInts->PushBack(11);
	queueWithInts->PushBack(23);

	EXPECT_EQ(2, queueWithInts->Size());
}
