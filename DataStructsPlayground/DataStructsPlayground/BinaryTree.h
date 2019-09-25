#pragma once

#include "TreeNode.h"
#include <queue>
#include <exception>

namespace Tree {
	class RemovingInvalidValueException : public std::exception {};

	// For many of the functions, we don't assume that the tree is complete.
	// Based on how we wrote Insert and Remove, we should be safe
	// to make that assumption and optimize the code a bit.

	template <typename T>
	class BinaryTree {
	public:
		virtual ~BinaryTree() {
			std::queue<TreeNode<T>*> nodes;
			nodes.push(root_);
			while (!nodes.empty()) {
				auto node = nodes.front();
				nodes.pop();
				if (node == nullptr) {
					continue;
				}
				nodes.push(node->Left());
				nodes.push(node->Right());
				delete node;
			}
		}

		inline void Insert(const T& data) {
			if (root_ == nullptr) {
				root_ = new TreeNode<T>(data);
			}
			else {
				std::queue<TreeNode<T>*> nodes;
				nodes.push(root_);
				while (!nodes.empty()) {
					auto node = nodes.front();
					nodes.pop();
					if (node->Left() == nullptr) {
						node->Left(new TreeNode<T>(data));
					}
					else if (node->Right() == nullptr) {
						node->Right(new TreeNode<T>(data));
					}
					else {
						nodes.push(node->Left());
						nodes.push(node->Right());
					}
				}
			}
		};

		inline void Remove(const T& data) {
			TreeNode<T>** target = nullptr;
			TreeNode<T>** current = nullptr;
			std::queue<TreeNode<T>**> nodes;
			nodes.push(&root_);
			while (*nodes.front() != nullptr) {
				current = nodes.front();
				nodes.pop();
				nodes.push((*current)->LeftAddr());
				nodes.push((*current)->RightAddr());
				if ((*current)->Data() == data) {
					target = current;
				}
			}
			if (target != nullptr) {
				std::swap(*target, *current);
				delete (*current);
				*current = nullptr;
			}
		};

		inline bool IsEmpty() { return root_ == nullptr; }

		inline bool Find(const T& data) {
			bool found = false;
			std::queue<TreeNode<T>*> nodes;
			nodes.push(root_);
			while (!nodes.empty()) {
				auto node = nodes.front();
				nodes.pop();
				if (node == nullptr) {
					continue;
				}
				else if (node->Data() == data) {
					found = true;
					break;
				}
				else {
					nodes.push(node->Left());
					nodes.push(node->Right());
				}
			}

			return found;
		}
		//template<typename Ret, typename Func>
		//Ret VisitInOrder(Func&& lambda) {
		//	return VisitInOrderHelper(head_, lambda);
		//}

	private:
		//template<typename Ret, typename Func>
		//Ret VisitInOrderHelper(TreeNode<T>* node, Func&& lambda) {
		//	VisitInOrderHelper(node->Left(), lambda);
		//	lambda()
		//}

		TreeNode<T>* root_ = nullptr;
	};
}