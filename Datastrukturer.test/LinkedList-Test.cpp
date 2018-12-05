#include "gtest/gtest.h"
#include "../Datastrukturer/Linkedlist.h"
#include "../Datastrukturer/SingleNode.h"


TEST(LinkedListTests, CheckThatAddedItemIsAtListHead) {
	Linkedlist<int> list;
	list.InsertFirst(9000, 1);
	EXPECT_EQ(9000, list.getHead().getData());

}

TEST(LinkedListTests, CheckThatWhenAddingNewItemListHeadIsMovedToNewItemNext) {
	Linkedlist<int> list;

	list.InsertFirst(9000, 1);
	list.InsertFirst(1, 2);
	SingleNode<int> tempNode = list.getHead();
	EXPECT_EQ(9000, tempNode.next->getData());
}