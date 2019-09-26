#include "pch.h"
#include "List.h"
#include "ListNode.h"

namespace PlaygroundUnitTests {
	TEST(List, DISABLED_MemoryLeakCheck) {
		for (int i = 0; i < 100000; ++i) {
			LinkedList::List<int> list;
			list.AppendBack(1);
			list.AppendBack(2);
			list.AppendBack(3);
			list.AppendBack(4);
			list.AppendBack(5);
		}
		EXPECT_TRUE(true);
	}

	TEST(List, SingleAppendSinglePop) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		auto data = list.PopFront();
		EXPECT_EQ(data, 1);
	}

	TEST(List, MultiAppendSinglePop) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		list.AppendBack(3);
		list.AppendBack(4);
		list.AppendBack(5);
		auto data = list.PopFront();
		EXPECT_EQ(data, 1);
	}

	TEST(List, MultiAppendMultiPop) {
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

	TEST(List, MultiAppendPopAll) {
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

	TEST(List, EmptyOnConstruction) {
		LinkedList::List<int> list;
		EXPECT_TRUE(list.IsEmpty());
	}

	TEST(List, NotEmptyAfterAppend) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		EXPECT_FALSE(list.IsEmpty());
	}

	TEST(List, EmptyAfterSingleAppendSinglePop) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		auto data = list.PopFront();
		EXPECT_TRUE(list.IsEmpty());
	}

	TEST(List, NotEmptyAfterMultiAppendSinglePop) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		auto data = list.PopFront();
		EXPECT_FALSE(list.IsEmpty());
	}

	TEST(List, EmptyAfterMultiAppendPopAll) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		auto data = list.PopFront();
		data = list.PopFront();
		EXPECT_TRUE(list.IsEmpty());
	}

	TEST(List, PopEmptyListException) {
		LinkedList::List<int> list;
		EXPECT_THROW(auto data = list.PopFront(), LinkedList::EmptyListException);
	}

	TEST(List, SuccessfulFind) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		auto found = list.Find(2);
		EXPECT_TRUE(found);
	}

	TEST(List, UnsuccessfulFind) {
		LinkedList::List<int> list;
		list.AppendBack(1);
		list.AppendBack(2);
		auto found = list.Find(3);
		EXPECT_FALSE(found);
	}
}