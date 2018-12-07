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
TEST(Doublelinkedlisttests, alltests) {
	Doublelinkedlist<int, int> testlist;
	DoubleNode<int, int> *testnode = new DoubleNode<int, int>(555, 5);
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	testlist.InsertFirst(125, 3);
	testlist.InsertFirst(126, 4);
	testlist.InsertAfterIndex(127, 5, 3);
	EXPECT_EQ(127, testlist.getTail()->prev->getData());
}