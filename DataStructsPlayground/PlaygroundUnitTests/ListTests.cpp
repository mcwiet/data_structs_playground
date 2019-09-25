#include "pch.h"
#include "List.h"
#include "ListNode.h"

namespace PlaygroundUnitTests {
	TEST(ListTests, SingleAppendSinglePop) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		auto data = list.PopFront();
		EXPECT_EQ(data, 1);
	}

	TEST(ListTests, MultiAppendSinglePop) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		list.AppendBack(3);
		list.AppendBack(4);
		list.AppendBack(5);
		auto data = list.PopFront();
		EXPECT_EQ(data, 1);
	}

	TEST(ListTests, MultiAppendMultiPop) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		list.AppendBack(3);
		list.AppendBack(4);
		list.AppendBack(5);
		auto data = list.PopFront();
		EXPECT_EQ(data, 1);
		data = list.PopFront();
		EXPECT_EQ(data, 2);
		data = list.PopFront();
		EXPECT_EQ(data, 3);
	}

	TEST(ListTests, MultiAppendPopAll) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		list.AppendBack(3);
		list.AppendBack(4);
		list.AppendBack(5);
		auto data = list.PopFront();
		EXPECT_EQ(data, 1);
		data = list.PopFront();
		EXPECT_EQ(data, 2);
		data = list.PopFront();
		EXPECT_EQ(data, 3);
		data = list.PopFront();
		EXPECT_EQ(data, 4);
		data = list.PopFront();
		EXPECT_EQ(data, 5);
	}

	TEST(ListTests, EmptyOnConstruction) {
		LinkedList::List<int> list;
		EXPECT_TRUE(list.IsEmpty());
	}

	TEST(ListTests, NotEmptyAfterAppend) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		EXPECT_FALSE(list.IsEmpty());
	}

	TEST(ListTests, EmptyAfterSingleAppendSinglePop) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		auto data = list.PopFront();
		EXPECT_TRUE(list.IsEmpty());
	}

	TEST(ListTests, NotEmptyAfterMultiAppendSinglePop) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		auto data = list.PopFront();
		EXPECT_FALSE(list.IsEmpty());
	}

	TEST(ListTests, EmptyAfterMultiAppendPopAll) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		auto data = list.PopFront();
		data = list.PopFront();
		EXPECT_TRUE(list.IsEmpty());
	}

	TEST(ListTests, PopEmptyListException) {
		LinkedList::List<int> list;
		EXPECT_THROW(auto data = list.PopFront(), LinkedList::EmptyListException);
	}

	TEST(ListTests, SuccessfulFind) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		auto found = list.Find(2);
		EXPECT_TRUE(found);
	}

	TEST(ListTests, UnsuccessfulFind) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		auto found = list.Find(3);
		EXPECT_FALSE(found);
	}
}