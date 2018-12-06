#include "gtest/gtest.h"
#include "../Datastrukturer/Queue.h"
#include <exception>

class QueueTest : public testing::Test
{
protected:
	Queue<int>* queue;

	virtual void SetUp()
	{
		queue = new Queue<int>(5);
	}

	virtual void TearDown()
	{
		delete queue;
	}
};


TEST_F(QueueTest, WhenQueueIsNotEmptyItShouldReturnNotEmpty)
{
	queue->PushBack(2);

	EXPECT_EQ(false, queue->IsEmpty());
}


TEST_F(QueueTest, WhenQueueIsNotEmptyAndNotFullItShouldReturnNotFull)
{
	queue->PushBack(2);

	EXPECT_EQ(false, queue->IsFull());
}


TEST_F(QueueTest, WhenQueueIsFullItShouldReturnIsFull)
{
	for (int i = 0; i < 5; i++)
	{
		queue->PushBack(i);
	}

	EXPECT_EQ(true, queue->IsFull());
}


TEST_F(QueueTest, WhenQueueIsEmptyPopFrontShouldThrowException)
{
	EXPECT_THROW(queue->PopFront(), std::underflow_error);
}


TEST_F(QueueTest, WhenQueueIsFullPushBackShouldThrowException)
{
	for (int i = 0; i < 5; i++)
	{
		queue->PushBack(i);
	}

	EXPECT_THROW(queue->PushBack(1), std::overflow_error);
}