#include "pch.h"
#include "DoubleListNode.h"
#include <string>

namespace PlaygroundUnitTests {
	namespace LinkedListTests {
		TEST(DoubleListNodeTests, ConstructWithData) {
			LinkedList::DoubleListNode<int> node1(5);
			LinkedList::DoubleListNode<float> node2(-20.0F);
			LinkedList::DoubleListNode<char> node3('q');
			LinkedList::DoubleListNode<std::string> node4("coffee is good");

			EXPECT_EQ(node1.Data(), 5);
			EXPECT_FLOAT_EQ(node2.Data(), -20.0F);
			EXPECT_EQ(node3.Data(), 'q');
			EXPECT_EQ(node4.Data(), "coffee is good");
		}

		TEST(DoubleListNodeTests, SetAndGetData) {
			LinkedList::DoubleListNode<int> node;
			node.Data(5);
			EXPECT_EQ(node.Data(), 5);
			node.Data(200);
			EXPECT_EQ(node.Data(), 200);
		}

		TEST(DoubleListNodeTests, NextDefaultsToNullptr) {
			LinkedList::DoubleListNode<int> node;
			EXPECT_EQ(node.Next(), nullptr);
		}

		TEST(DoubleListNodeTests, PrevDefaultsToNullptr) {
			LinkedList::DoubleListNode<int> node;
			EXPECT_EQ(node.Prev(), nullptr);
		}

		TEST(DoubleListNodeTests, SetAndGetNextNode) {
			LinkedList::DoubleListNode<int> head;
			LinkedList::DoubleListNode<int> tail;
			head.Next(&tail);
			LinkedList::DoubleListNode<int>* current = &head;
			EXPECT_NE(current, &tail);
			current = current->Next();
			EXPECT_EQ(current, &tail);
		}

		TEST(DoubleListNodeTests, SetAndGetPrevNode) {
			LinkedList::DoubleListNode<int> head;
			LinkedList::DoubleListNode<int> tail;
			tail.Prev(&head);
			LinkedList::DoubleListNode<int>* current = &tail;
			EXPECT_NE(current, &head);
			current = current->Prev();
			EXPECT_EQ(current, &head);
		}

		TEST(DoubleListNodeTests, ConstructWithNext) {
			LinkedList::DoubleListNode<int> tail;
			LinkedList::DoubleListNode<int> head(&tail);
			EXPECT_EQ(head.Next(), &tail);
		}

		TEST(DoubleListNodeTests, ConstructWithNextAndPrev) {
			LinkedList::DoubleListNode<int> tail;
			LinkedList::DoubleListNode<int> head;
			LinkedList::DoubleListNode<int> mid(&tail, &head);
			EXPECT_EQ(mid.Next(), &tail);
			EXPECT_EQ(mid.Prev(), &head);
		}

		TEST(DoubleListNodeTests, DataNotStoredAsReference) {
			LinkedList::DoubleListNode<int> node;
			int x = 5;
			node.Data(x);
			x = 10;
			EXPECT_NE(node.Data(), x);
		}
	}
}