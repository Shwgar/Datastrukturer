#include "gtest/gtest.h"
#include "../Datastrukturer/Linkedlist.h"
#include "../Datastrukturer/SingleNode.h"


TEST(LinkedListTests, CheckThatAddedItemIsAtListHead) {
	Linkedlist<int, int> list;
	int returnNumber = list.getData();
	list.InsertFirst(9000, 1);
	EXPECT_EQ(9000, list.getData());
}

TEST(LinkedListTests, CheckThatWhenAddingNewItemListHeadIsMovedToNewItemNext) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(1, 2);
	EXPECT_EQ(9000, list.;
}