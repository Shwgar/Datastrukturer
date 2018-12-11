#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "gtest/gtest.h"
#include "../Datastrukturer/Linkedlist.h"
#include "../Datastrukturer/SingleNode.h"
#include <vector>


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

TEST(LinkedListTests, CheckIfSearchReturnsThrowIfNotFound) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	EXPECT_THROW(int testReturn = list.Search(7), std::invalid_argument);
}

TEST(LinkedListTests, CheckIfSearchAfterDeleteReturnsNull) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	list.DeleteKey(3);
	EXPECT_THROW(int testReturn = list.Search(3), std::invalid_argument);
}


TEST(LinkedListTests, CheckIfSearchReturnsRightDataWithVectors) {
	Linkedlist<std::vector<int>, int> list;
	std::vector<int> vect1;
	std::vector<int> vect2;
	std::vector<int> vect3;
	vect1.push_back(10);
	vect2.push_back(20);
	vect3.push_back(30);
	list.InsertFirst(vect1, 1);
	list.InsertFirst(vect2, 2);
	list.InsertFirst(vect3, 3);
	std::vector<int> testReturn = list.Search(3);
	EXPECT_EQ(30, testReturn.at(0));
}

