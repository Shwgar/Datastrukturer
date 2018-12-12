#include "gtest/gtest.h"
#include "../Datastrukturer/Doublelinkedlist.h"
TEST(Doublelinkedlisttests, WhenAddingOneThingToListHeadShouldBeWhatYouAdded) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	EXPECT_EQ(123, testlist.getHead());
  
}
TEST(Doublelinkedlisttests, WhenAddingTwoThingsToListHeadShouldBeWhatYouAddedLast) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_EQ(124, testlist.getHead());

}
TEST(Doublelinkedlisttests, WhenAddingTwoThingsToListTailShouldBeWhatYouAddedFirst) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_EQ(123, testlist.getTail());

}
TEST(Doublelinkedlisttests, WhenAddingThreeThingsToListTheMiddleShouldPointToHead) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_EQ(123, testlist.getTail());
}
TEST(Doublelinkedlisttests, GetCountShouldReturnListSize) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_EQ(2, testlist.GetCount());
}
TEST(Doublelinkedlisttests, GetHeadShouldReturnLastInsertFirstData) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	testlist.InsertFirst(125, 3);
	int recieved = testlist.getHead();

	EXPECT_EQ(125, recieved);
}
TEST(Doublelinkedlisttests, GetTailShouldReturnFirstInsertFirstData) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	testlist.InsertFirst(125, 3);
	int recieved = testlist.getTail();

	EXPECT_EQ(123, recieved);
}
TEST(Doublelinkedlisttests, WhenInsertingLastOneTimeHeadShouldBeWhatYouAdd) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertLast(123, 1);
	EXPECT_EQ(123, testlist.getHead());
}
TEST(Doublelinkedlisttests, WhenInsertingLastOneTimeTailShouldBeWhatYouAdd) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertLast(123, 1);
	EXPECT_EQ(123, testlist.getTail());
}
TEST(Doublelinkedlisttests, WhenInsertingLastTwoTimesTailShouldBeTheLatestYouAdd) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertLast(123, 1);
	testlist.InsertLast(124, 2);
	testlist.InsertLast(125, 3);
	EXPECT_EQ(125, testlist.getTail());
}
TEST(Doublelinkedlisttests, WhenInsertingAfterTheFirstOneTailShouldBeWhatYouAdd) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertLast(124, 2);
	testlist.InsertAfterIndex(125, 3, testlist.GetCount());
	EXPECT_EQ(125, testlist.getTail());
}
TEST(Doublelinkedlisttests, InsertingFirstLastAndAfterSameDataMiddleShouldBeCorrect) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123,1);
	testlist.InsertLast(124,2);
	testlist.InsertAfterIndex(125, 3, testlist.GetCount());

	EXPECT_EQ(124, testlist.Search(2));
}
TEST(Doublelinkedlisttests, DeletingFirstShouldReturnWhatYouLastInsertedFirst) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	testlist.InsertFirst(125, 3);
	int recieved = testlist.DeleteFirst();

	EXPECT_EQ(125, recieved);
}
TEST(Doublelinkedlisttests, DeleteFirstShouldThrowExceptionWhenSearchingforThatKey) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	testlist.InsertFirst(125, 3);
	testlist.DeleteFirst();

	EXPECT_THROW(testlist.Search(3), std::invalid_argument);
}
TEST(Doublelinkedlisttests, DeleteLastShouldReturnWhatYouFirstInsertedFirst) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	testlist.InsertFirst(125, 3);
	int recieved = testlist.DeleteLast();

	EXPECT_EQ(123, recieved);
}
TEST(Doublelinkedlisttests, DeleteLastShouldThrowExceptionWhenSearchingforThatKey) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	testlist.InsertFirst(125, 3);
	testlist.DeleteLast();

	EXPECT_THROW(testlist.Search(1),std::invalid_argument);
}
TEST(Doublelinkedlisttests, DeleteKeyWithEmptyListShouldThrowException) {
	Doublelinkedlist<int, int> testlist;
	EXPECT_THROW(testlist.DeleteKey(1), std::underflow_error);
}
TEST(Doublelinkedlisttests, DeleteLastWithEmptyListShouldThrowException) {
	Doublelinkedlist<int, int> testlist;
	EXPECT_THROW(testlist.DeleteLast(), std::underflow_error);
}
TEST(Doublelinkedlisttests, DeleteFirstWithEmptyListShouldThrowException) {
	Doublelinkedlist<int, int> testlist;
	EXPECT_THROW(testlist.DeleteFirst(), std::underflow_error);
}
TEST(Doublelinkedlisttests, DeleteKeyWithInvalidKeyShouldThrowException) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_THROW(testlist.DeleteKey(3), std::invalid_argument);
}
TEST(Doublelinkedlisttests, ListWithVectorShouldWork) {
	Doublelinkedlist<std::vector<int>, int> testlist;
	std::vector<int> test;
	test.push_back(1);
	testlist.InsertFirst(test, 1);
	test.push_back(2);
	testlist.InsertFirst(test, 2);
	test.push_back(3);
	testlist.InsertFirst(test, 3);
	testlist.DeleteKey(2);
	EXPECT_EQ(3, testlist.Search(3).at(2));
}
TEST(Doublelinkedlisttests, whenThereIsSameKeyMultipleTimesSearchShouldReturnTheFirstKeyInList) {
	Doublelinkedlist<std::string, int> testlist;
	testlist.InsertFirst("hej", 1);
	testlist.InsertFirst("du", 1);
	testlist.InsertFirst("dar", 1);
	EXPECT_EQ("dar", testlist.Search(1));
}
TEST(Doublelinkedlisttests, TestToMakeSureLinkingStillWorksCorrectly) {
	Doublelinkedlist<std::string, int> testlist;
	testlist.InsertFirst("hej", 1);
	testlist.InsertFirst("du", 1);
	testlist.InsertFirst("dar", 1);
	testlist.InsertAfterKey("dur", 2, 1);
	testlist.DeleteKey(2);
	testlist.DeleteKey(1);

	EXPECT_EQ("du", testlist.Search(1));
}
TEST(Doublelinkedlisttests, InsertTwoNodesAndDeleteOneGetCountShouldReturnCorrectValue) {
	Doublelinkedlist<std::string, int> testlist;
	testlist.InsertFirst("hej", 1);
	testlist.InsertFirst("du", 1);
	testlist.DeleteKey(1);

	EXPECT_EQ(1, testlist.GetCount());
}
TEST(Doublelinkedlisttests, SearchWhenListIsEmptyShouldThrowException) {
	Doublelinkedlist<std::string, int> testlist;

	EXPECT_THROW(testlist.Search(1), std::underflow_error);
}
TEST(Doublelinkedlisttests, SearchForKeyThatDoesNotExistShouldThrowEception) {
	Doublelinkedlist<std::string, int> testlist;
	testlist.InsertFirst("hej", 2);
	testlist.InsertAfterKey("hej", 1, 2);
	EXPECT_THROW(testlist.Search(3), std::invalid_argument);
}
TEST(Doublelinkedlisttests, SearchShouldReturnCorrectData) {
	Doublelinkedlist<std::string, int> testlist;
	testlist.InsertFirst("hej", 2);
	testlist.InsertAfterKey("hejjj", 1, 2);
	EXPECT_EQ("hej", testlist.Search(2));
}
TEST(Doublelinkedlisttests, InsertAfterKeyShouldBecomeTailIfKeyIsTail) {
	Doublelinkedlist<std::string, int> testlist;
	testlist.InsertFirst("hej", 2);
	testlist.InsertLast("daa", 1);
	testlist.InsertAfterKey("hejjj", 3, 1);
	EXPECT_EQ("hejjj", testlist.getTail());
}
