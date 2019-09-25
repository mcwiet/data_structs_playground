#include "pch.h"
#include "TreeNode.h"

namespace PlaygroundUnitTests {
	TEST(TreeNode, ConstructWithVariousTypes) {
		Tree::TreeNode<int> node1(5);
		Tree::TreeNode<float> node2(-20.0F);
		Tree::TreeNode<char> node3('q');
		Tree::TreeNode<std::string> node4("coffee is good");

		EXPECT_EQ(node1.Data(), 5);
		EXPECT_FLOAT_EQ(node2.Data(), -20.0F);
		EXPECT_EQ(node3.Data(), 'q');
		EXPECT_EQ(node4.Data(), "coffee is good");
	}

	TEST(TreeNode, LeftAndRightDefaultNullptr) {
		Tree::TreeNode<int> node(10);
		EXPECT_EQ(node.Left(), nullptr);
		EXPECT_EQ(node.Right(), nullptr);
	}

	TEST(TreeNode, SetAndGetData) {
		Tree::TreeNode<int> node(10);
		int data = -1;
		node.Data(data);
		EXPECT_EQ(node.Data(), data);
	}

	TEST(TreeNode, DataNotStoredAsReference) {
		Tree::TreeNode<int> node(10);
		int data = -1;
		node.Data(data);
		data = -50;
		EXPECT_NE(node.Data(), data);
	}

	TEST(TreeNode, SetAndGetLeftAndRight) {
		Tree::TreeNode<int> root(10);
		Tree::TreeNode<int> left(5);
		Tree::TreeNode<int> right(15);
		root.Left(&left);
		root.Right(&right);
		EXPECT_EQ(root.Left(), &left);
		EXPECT_EQ(root.Right(), &right);
	}
}