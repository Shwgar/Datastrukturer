#include "gtest/gtest.h"
#include "../Datastrukturer/Doublelinkedlist.h"
TEST(Doublelinkedlisttests, WhenAddingOneThingToListHeadShouldBeWhatYouAdded) {
	Doublelinkedlist<int> testlist;
	testlist.InsertFirst(123, 1);
	EXPECT_EQ(123, testlist.getHead());
  
}
TEST(Doublelinkedlisttests, WhenAddingTwoThingsToListHeadShouldBeWhatYouAddedLast) {
	Doublelinkedlist<int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_EQ(124, testlist.getHead());

}
TEST(Doublelinkedlisttests, WhenAddingTwoThingsToListTailShouldBeWhatYouAddedFirst) {
	Doublelinkedlist<int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_EQ(123, testlist.getTail());

}
TEST(Doublelinkedlisttests, WhenAddingThreeThingsToListTheMiddleShouldPointToHead) {
	Doublelinkedlist<int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_EQ(123, testlist.getTail());
}