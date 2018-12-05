#include "gtest/gtest.h"
#include "../Datastrukturer/Doublelinkedlist.h"
TEST(Doublelinkedlisttests, WhenAddingOneThingToListHeadShouldBeWhatYouAdded) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	EXPECT_EQ(123, testlist.getHead()->getData());
  
}
TEST(Doublelinkedlisttests, WhenAddingTwoThingsToListHeadShouldBeWhatYouAddedLast) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_EQ(124, testlist.getHead()->getData());

}
TEST(Doublelinkedlisttests, WhenAddingTwoThingsToListTailShouldBeWhatYouAddedFirst) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_EQ(123, testlist.getTail()->getData());

}
TEST(Doublelinkedlisttests, WhenAddingThreeThingsToListTheMiddleShouldPointToHead) {
	Doublelinkedlist<int, int> testlist;
	testlist.InsertFirst(123, 1);
	testlist.InsertFirst(124, 2);
	EXPECT_EQ(123, testlist.getTail()->getData());
}