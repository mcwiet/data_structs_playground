#include "pch.h"
#include "BinarySearchTree.h"
#include "ExceptionRemovingInvalidTreeNode.h"

namespace BinarySearchTree {
	TEST(BinarySearchTree, DISABLED_MemoryLeakCheck) {
		for (int i = 0; i < 10000; ++i) {
			Tree::BinarySearchTree<int> tree;
			tree.Insert(10);
			tree.Insert(5);
			tree.Insert(-6);
			tree.Insert(2);
			tree.Insert(5);
			tree.Remove(10);
			tree.Remove(-6);
		}
		EXPECT_TRUE(true);
	}

	TEST(BinarySearchTree, EmptyAfterConstruction) {
		Tree::BinarySearchTree<int> tree;
		EXPECT_TRUE(tree.IsEmpty());
	}

	TEST(BinarySearchTree, NotEmptyAfterInsert) {
		Tree::BinarySearchTree<int> tree;
		tree.Insert(10);
		EXPECT_FALSE(tree.IsEmpty());
	}

	TEST(BinarySearchTree, FindInEmptyTree) {
		Tree::BinarySearchTree<int> tree;
		EXPECT_FALSE(tree.Find(10));
	}

	TEST(BinarySearchTree, SuccessfulFind) {
		Tree::BinarySearchTree<int> tree;
		tree.Insert(10);
		tree.Insert(5);
		tree.Insert(-6);
		EXPECT_TRUE(tree.Find(5));
	}

	TEST(BinarySearchTree, UnsuccessfulFind) {
		Tree::BinarySearchTree<int> tree;
		tree.Insert(10);
		tree.Insert(5);
		tree.Insert(-6);
		EXPECT_FALSE(tree.Find(-20));
	}

	TEST(BinarySearchTree, UnsuccessfulFindAfterRemovalSingleNodeTree) {
		Tree::BinarySearchTree<int> tree;
		tree.Insert(10);
		EXPECT_TRUE(tree.Find(10));
		tree.Remove(10);
		EXPECT_FALSE(tree.Find(10));
	}

	TEST(BinarySearchTree, UnsuccessfulFindAfterRemovalMultiNodeTree) {
		Tree::BinarySearchTree<int> tree;
		tree.Insert(10);
		tree.Insert(25);
		tree.Insert(-5);
		tree.Insert(7657);
		tree.Insert(-432738);
		EXPECT_TRUE(tree.Find(7657));
		tree.Remove(7657);
		EXPECT_FALSE(tree.Find(7657));
	}

	TEST(BinarySearchTree, NoExceptionRemovingValueInTree) {
		Tree::BinarySearchTree<int> tree;
		tree.Insert(10);
		EXPECT_NO_THROW(tree.Remove(10));
	}

	TEST(BinarySearchTree, ExceptionRemovingValueNotInTree) {
		Tree::BinarySearchTree<int> tree;
		EXPECT_THROW(tree.Remove(10), Tree::ExceptionRemovingInvalidTreeNode);
	}

	void SetupTreeForVisitTests(Tree::BinarySearchTree<int>& tree) {
		tree.Insert(2);
		tree.Insert(15);
		tree.Insert(-5);
		tree.Insert(-4);
		tree.Insert(3);
		tree.Insert(-8);
		tree.Remove(2);  // Removing node with double child
		tree.Insert(-5); // Adding duplicate
		tree.Insert(12);
		tree.Remove(15); // Removing node with single child
		tree.Remove(-4); // Removing node with no child

		/* Final result should look like:
					3
				 -5   12
			   -8
		*/
	}

	TEST(BinarySearchTree, InOrderVisitNums) {
		Tree::BinarySearchTree<int> tree;
		SetupTreeForVisitTests(tree);
		std::string nums = "";
		auto build_string = [&](Tree::TreeNode<int>* node) {
			nums += (std::to_string(node->Data()) + ",");
		};
		tree.VisitInOrder(build_string);

		EXPECT_EQ(nums, "-8,-5,3,12,");
	}

	TEST(BinarySearchTree, PreOrderVisitNums) {
		Tree::BinarySearchTree<int> tree;
		SetupTreeForVisitTests(tree);
		std::string nums = "";
		auto build_string = [&](Tree::TreeNode<int>* node) {
			nums += (std::to_string(node->Data()) + ",");
		};
		tree.VisitPreOrder(build_string);

		EXPECT_EQ(nums, "3,-5,-8,12,");
	}

	TEST(BinarySearchTree, PostOrderVisitNums) {
		Tree::BinarySearchTree<int> tree;
		SetupTreeForVisitTests(tree);
		std::string nums = "";
		auto build_string = [&](Tree::TreeNode<int>* node) {
			nums += (std::to_string(node->Data()) + ",");
		};
		tree.VisitPostOrder(build_string);

		EXPECT_EQ(nums, "-8,-5,12,3,");
	}

	TEST(BinarySearchTree, RValueReferenceInVisit) {
		Tree::BinarySearchTree<char> tree;

		tree.Insert('a');
		tree.Insert('b');
		tree.Insert('c');
		tree.Insert('d');
		tree.Insert('e');
		tree.Insert('f');
		tree.Insert('g');

		std::string letters = "";
		auto mark_visited = [](Tree::TreeNode<char>* node, char new_letter) { node->Data(new_letter); };
		auto build_string = [&](Tree::TreeNode<char>* node) { letters += node->Data(); };
		tree.VisitPostOrder(mark_visited, 'v');
		tree.VisitPostOrder(build_string);

		EXPECT_EQ(letters, "vvvvvvv");
	}

	TEST(BinarySearchTree, MutableLambdaInVisit) {
		// This test is super contrived and is just here to prove that, if needed, you could use a mutable lambda
		Tree::BinarySearchTree<char> tree;

		tree.Insert('a');
		tree.Insert('b');
		tree.Insert('c');
		tree.Insert('d');
		tree.Insert('e');
		tree.Insert('f');
		tree.Insert('g');

		char new_letter = '\n';
		auto mark_visited = [=](Tree::TreeNode<char>* node) mutable { new_letter = 'v';  node->Data(new_letter); };
		std::string letters = "";
		auto build_string = [&](Tree::TreeNode<char>* node) { letters += node->Data(); };
		tree.VisitPostOrder(mark_visited);
		tree.VisitPostOrder(build_string);

		EXPECT_EQ(letters, "vvvvvvv");
	}
}