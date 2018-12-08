#include "gtest/gtest.h"
#include "../Datastrukturer/Queue.h"
#include <exception>

class QueueTest : public testing::Test
{
protected:
	const unsigned int capacity = 5;

	Queue<int>* queueWithInts;
	Queue<float>* queueWithFloats;

	virtual void SetUp()
	{
		queueWithInts = new Queue<int>(capacity);
		queueWithFloats = new Queue<float>(capacity);
	}

	virtual void TearDown()
	{
		delete queueWithInts;
		delete queueWithFloats;
	}

	virtual void FillQueueWithInts()
	{
		for (int i = 0; i < capacity; i++)
		{
			queueWithInts->PushBack(i);
		}
	}
};


TEST_F(QueueTest, QueueWithFloatsShouldReturnFloats)
{
	queueWithFloats->PushBack(1.0f);
	queueWithFloats->PushBack(2.0f);

	EXPECT_EQ(1.0f, queueWithFloats->PopFront());
}


TEST_F(QueueTest, WhenQueueIsNotEmptyItShouldReturnNotEmpty)
{
	queueWithInts->PushBack(1);

	EXPECT_EQ(false, queueWithInts->IsEmpty());
}


TEST_F(QueueTest, WhenQueueIsEmptyItShouldReturnEmpty)
{
	EXPECT_EQ(true, queueWithInts->IsEmpty());
}



TEST_F(QueueTest, WhenQueueIsNotEmptyAndNotFullItShouldReturnNotFull)
{
	queueWithInts->PushBack(1);

	EXPECT_EQ(false, queueWithInts->IsFull());
}


TEST_F(QueueTest, WhenQueueIsFullItShouldReturnIsFull)
{
	FillQueueWithInts();

	EXPECT_EQ(true, queueWithInts->IsFull());
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
