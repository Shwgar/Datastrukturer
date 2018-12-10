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

	//EXPECT_EQ(124, testlist.getHead()->next->getData());
}
TEST(Doublelinkedlisttests, DeletingFirstShouldReturnWhatYouLastInsertedFirst) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	testlist.InsertFirst(125, 3);
	int recieved = testlist.DeleteFirst();

	EXPECT_EQ(125, recieved);
}
//TEST(Doublelinkedlisttests, DeletingFirstShouldReturnWhatYouLastInsertedFirst) {
//	Doublelinkedlist<int, int> testlist;
//	testlist.InsertFirst(123, 1);
//	testlist.InsertFirst(124, 2);
//	testlist.InsertFirst(125, 3);
//	int recieved = testlist.DeleteFirst();
//
//	EXPECT_EQ(125, recieved);
//}
TEST(Doublelinkedlisttests, DeleteLastShouldReturnWhatYouFirstInsertedFirst) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	testlist.InsertFirst(125, 3);
	int recieved = testlist.DeleteLast();

	EXPECT_EQ(123, recieved);
}
TEST(Doublelinkedlisttests, DeleteLastShouldRemoveWhatYouInsertedFirst) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	testlist.InsertFirst(125, 3);
	testlist.DeleteLast();

	EXPECT_THROW(testlist.Search(1),std::invalid_argument);
}
//TEST(Doublelinkedlisttests, DeleteLastShouldRemoveWhatYouInsertedFirst) {
//	Doublelinkedlist<int, int> testlist;
//	testlist.InsertFirst(123, 1);
//	testlist.InsertFirst(124, 2);
//	testlist.InsertFirst(125, 3);
//	testlist.DeleteLast();
//
//	EXPECT_THROW(testlist.Search(1), std::invalid_argument);
//}
TEST(Doublelinkedlisttests, DeleteKeyWithEmptyListShouldThrowException) {
	Doublelinkedlist<int, int> testlist;
	EXPECT_THROW(testlist.DeleteKey(1), std::underflow_error);
}
TEST(Doublelinkedlisttests, DeleteKeyWithInvalidKeyShouldThrowException) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_THROW(testlist.DeleteKey(3), std::invalid_argument);
}