#include "pch.h"
#include "BinaryTree.h"
#include <functional>
#include <iostream>

namespace PlaygroundUnitTests {
	TEST(BinaryTree, DISABLED_MemoryLeakCheck) {
		for (int i = 0; i < 10000; ++i) {
			Tree::BinaryTree<int> tree;
			tree.Insert(10);
			tree.Insert(5);
			tree.Insert(-6);
			tree.Insert(2);
			tree.Insert(5);
		}
		EXPECT_TRUE(true);
	}

	TEST(BinaryTree, EmptyAfterConstruction) {
		Tree::BinaryTree<int> tree;
		EXPECT_TRUE(tree.IsEmpty());
	}

	TEST(BinaryTree, NotEmptyAfterInsert) {
		Tree::BinaryTree<int> tree;
		tree.Insert(10);
		EXPECT_FALSE(tree.IsEmpty());
	}

	TEST(BinaryTree, FindInEmptyTree) {
		Tree::BinaryTree<int> tree;
		EXPECT_FALSE(tree.Find(10));
	}

	TEST(BinaryTree, SuccessfulFind) {
		Tree::BinaryTree<int> tree;
		tree.Insert(10);
		tree.Insert(5);
		tree.Insert(-6);
		EXPECT_TRUE(tree.Find(5));
	}

	TEST(BinaryTree, UnsuccessfulFind) {
		Tree::BinaryTree<int> tree;
		tree.Insert(10);
		tree.Insert(5);
		tree.Insert(-6);
		EXPECT_FALSE(tree.Find(-20));
	}

	TEST(BinaryTree, UnsuccessfulFindAfterRemovalSingleNodeTree) {
		Tree::BinaryTree<int> tree;
		tree.Insert(10);
		EXPECT_TRUE(tree.Find(10));
		tree.Remove(10);
		EXPECT_FALSE(tree.Find(10));
	}

	TEST(BinaryTree, UnsuccessfulFindAfterRemovalMultiNodeTree) {
		Tree::BinaryTree<int> tree;
		tree.Insert(10);
		tree.Insert(25);
		tree.Insert(-5);
		tree.Insert(7657);
		tree.Insert(-432738);
		EXPECT_TRUE(tree.Find(7657));
		tree.Remove(7657);
		EXPECT_FALSE(tree.Find(7657));
	}

	TEST(BinaryTree, NoExceptionRemovingValueInTree) {
		Tree::BinaryTree<int> tree;
		tree.Insert(10);
		EXPECT_NO_THROW(tree.Remove(10));
	}

	TEST(BinaryTree, ExceptionRemovingValueNotInTree) {
		Tree::BinaryTree<int> tree;
		EXPECT_THROW(tree.Remove(10), Tree::RemovingInvalidValueException);
	}

	TEST(BinaryTree, InOrderVisitSum) {
		Tree::BinaryTree<char> tree;

		tree.Insert('a');
		tree.Insert('b');
		tree.Insert('c');
		tree.Insert('d');
		tree.Insert('e');
		tree.Insert('f');
		tree.Insert('g');

		std::string letters = "";
		auto func = [&](Tree::TreeNode<char>* node) { letters += node->Data(); };
		tree.VisitInOrder(func);

		EXPECT_EQ(letters, "dbeafcg");
	}
}