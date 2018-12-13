#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "gtest/gtest.h"
#include "../Datastrukturer/Linkedlist.h"
#include "../Datastrukturer/SingleNode.h"
#include <vector>


TEST(LinkedListTests, WhenAddingItemIsAtListHead) {

	Linkedlist<int, int> list;;
	list.InsertFirst(9000, 1);
	EXPECT_EQ(9000, list.getHeadData());

}

TEST(LinkedListTests, WhenAddingNewItemFirstAddedIsNotAtHead) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(1, 2);

	EXPECT_NE(9000, list.getHeadData());
}

TEST(LinkedListTests, WhenAddingAfterIndexReturnsTrue) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	bool test = list.InsertAfterIndex(5, 5, 2);
	EXPECT_TRUE(test);
}

TEST(LinkedListTests, WhenAddingAfterKeyReturnsTrue) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	bool test = list.InsertAfterKey(5,5,3);
	EXPECT_TRUE(test);
}

TEST(LinkedListTests, WhenSearchingReturnsRightData) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	int testReturn = list.Search(3);
	EXPECT_EQ(3, testReturn);
}

TEST(LinkedListTests, WhenSearchingReturnsThrowIfNotFound) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	EXPECT_THROW(int testReturn = list.Search(7), std::invalid_argument);
}

TEST(LinkedListTests, WhenSearchingAfterDeleteReturnsThrow) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	list.DeleteKey(3);
	EXPECT_THROW(int testReturn = list.Search(3), std::invalid_argument);
}


TEST(LinkedListTests, WhenSearchingReturnsRightDataWithVectors) {
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

TEST(LinkedListTests, WhenTryingToDeleteIndexInEmptyListReturnShouldBeFalse) {
	Linkedlist<std::vector<int>, int> list;
	bool result = list.DeleteIndex(2);
	EXPECT_EQ(false, result);
}

TEST(LinkedListTests, WhenTryingToDeleteKeyInEmptyListReturnShouldBeFalse) {
	Linkedlist<std::vector<int>, int> list;
	bool result = list.DeleteKey(3);
	EXPECT_EQ(false, result);
}

TEST(LinkedListTests, WhenGetingCountFromListShouldBeSameAsInsertedInTemplate) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	int count = list.GetCount();
	EXPECT_EQ(2, count);
}

TEST(LinkedListTests, WhenDeletingVectorAndKeyNotFoundShouldReturnFalse) {
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
	bool result = list.DeleteKey(5);
	EXPECT_EQ(false, result);
}

TEST(LinkedListTests, WhenDeletingVectorThenVectorShoudNotBeFound) {
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
  list.DeleteKey(2);
	EXPECT_THROW(std::vector<int> testReturn = list.Search(2), std::invalid_argument);
}

TEST(LinkedListTests, WhenTryingToDeleteMinusIndexnumberShouldReturnFalse) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	bool result = list.DeleteIndex(-1);
	EXPECT_EQ(false, result);
}

TEST(LinkedListTests, WhenDeletingTemplateObjectInListWithOnlyTwoItemsListCountShouldGoDown) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(9001, 2);
  list.DeleteIndex(1);
	int listSize = list.GetCount();
	EXPECT_EQ(1, listSize);
}

TEST(LinkedListTests, WhenDeletingTemplateObjectInListWithMoreItemsListCountShouldGoDown) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	list.DeleteIndex(1);
	int listSize = list.GetCount();
	EXPECT_EQ(3, listSize);
}

TEST(LinkedListTests, TestToSeeThatListContainsAllInputs) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	int one = list.Search(1);
	int two = list.Search(2);
	int three = list.Search(3);
	int four = list.Search(4);
	int total = one + two + three + four;
	EXPECT_EQ(9009, total);
}

TEST(LinkedListTests, WhenAddingAfterIndexItemAfterIndexShouldStillExists) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	list.InsertAfterIndex(5, 5, 2);
	int returnvalue = list.Search(3);
	EXPECT_EQ(3, returnvalue);
}


TEST(LinkedListTests, WhenAddingAfterKeyItemAfterIndexShouldStillExists) {
	Linkedlist<int, int> list;
	list.InsertFirst(9000, 1);
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	list.InsertFirst(4, 4);
	list.InsertAfterKey(5, 5, 2);
	int returnvalue = list.Search(3);
	EXPECT_EQ(3, returnvalue);
}

TEST(LinkedListTests, WhenCreatingObjectLinkedlistListSizeShouldBeZero) {
	Linkedlist<int, int> list;
	int size = list.GetCount();
	EXPECT_EQ(0, size);
}

TEST(LinkedListTests, WhenInsertingSeveralObjectsHeadDataShouldReturnLastInsertedData) {
	Linkedlist<int, int> list;
	list.InsertFirst(2, 2);
	list.InsertFirst(3, 3);
	EXPECT_EQ(3, list.getHeadData());
}