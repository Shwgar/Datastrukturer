#include "gtest/gtest.h"
#include "../Datastrukturer/Linkedlist.h"
#include "../Datastrukturer/SingleNode.h"


TEST(LinkedListTests, CheckThatAddedItemIsAtListHead) {

	Linkedlist<int, int> list;;
	list.InsertFirst(9000, 1);
	EXPECT_EQ(9000, list.getHeadData());

}

TEST(LinkedListTests, CheckThatWhenAddingNewItemFirstAddedIsNotAtHead) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(1, 2);
	//SingleNode<int, int> *temp = list.getHead()->next;
	EXPECT_NE(9000, list.getHeadData());
}

TEST(LinkedListTests, CheckThatAddingAfterIndexReturnsTrue) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	bool test = list.InsertAfterIndex(5, 5, 2);
	EXPECT_TRUE(test);
}

TEST(LinkedListTests, CheckThatAddingAfterKeyReturnsTrue) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	bool test = list.InsertAfterKey(5,5,3);
	EXPECT_TRUE(test);
}

TEST(LinkedListTests, CheckIfSearchReturnsRightData) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	int testReturn = list.Search(3);
	EXPECT_EQ(3, testReturn);
}

TEST(LinkedListTests, CheckIfSearchReturnsNoDataIfNotFound) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	int testReturn = list.Search(7);
	EXPECT_EQ(NULL, testReturn);
}