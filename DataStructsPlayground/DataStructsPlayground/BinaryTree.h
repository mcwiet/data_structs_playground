#pragma once

#include "TreeNode.h"
#include <queue>
#include <exception>
#include <functional>

// Note: Class is written to assume that the tree will always be a complete tree.

namespace Tree {
	class RemovingInvalidValueException : public std::exception {};

	template <typename T>
	class BinaryTree {
	public:
		virtual ~BinaryTree() {
			std::queue<TreeNode<T>*> nodes;
			nodes.push(root_);
			while (nodes.front() != nullptr) {
				auto node = nodes.front();
				nodes.pop();
				nodes.push(node->Left());
				nodes.push(node->Right());
				delete node;
			}
		}

		inline void Insert(const T& data) {
			std::queue<TreeNode<T>**> nodes;
			nodes.push(&root_);
			while (*nodes.front() != nullptr) {
				auto current = nodes.front();
				nodes.pop();
				nodes.push((*current)->LeftAddr());
				nodes.push((*current)->RightAddr());
			}
			*nodes.front() = new TreeNode<T>(data);
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
			else {
				throw RemovingInvalidValueException();
			}
		};

		inline bool Find(const T& data) {
			bool found = false;
			std::queue<TreeNode<T>*> nodes;
			nodes.push(root_);
			while (nodes.front() != nullptr) {
				auto current = nodes.front();
				nodes.pop();
				if (current->Data() == data) {
					found = true;
					break;
				}
				nodes.push(current->Left());
				nodes.push(current->Right());
			}

			return found;
		}

		inline bool IsEmpty() { return root_ == nullptr; }

		template<typename Func, typename... Args>
		void VisitInOrder(Func&& visit_func, Args&& ... args) {
			VisitInOrderHelper(root_, visit_func, args...);
		}

		template<typename Func, typename... Args>
		void VisitPreOrder(Func&& visit_func, Args&& ... args) {
			VisitPreOrderHelper(root_, visit_func, args...);
		}

		template<typename Func, typename... Args>
		void VisitPostOrder(Func&& visit_func, Args&& ... args) {
			VisitPostOrderHelper(root_, visit_func, args...);
		}

	private:
		template<typename Func, typename... Args>
		void VisitInOrderHelper(TreeNode<T>* node, Func&& func, Args&& ... args) {
			if (node == nullptr)
				return;

			VisitInOrderHelper(node->Left(), func, args...);
			func(node, args...);
			VisitInOrderHelper(node->Right(), func, args...);
		}

		template<typename Func, typename... Args>
		void VisitPreOrderHelper(TreeNode<T>* node, Func&& func, Args&& ... args) {
			if (node == nullptr)
				return;

			func(node, args...);
			VisitPreOrderHelper(node->Left(), func, args...);
			VisitPreOrderHelper(node->Right(), func, args...);
		}

		template<typename Func, typename... Args>
		void VisitPostOrderHelper(TreeNode<T>* node, Func&& func, Args&& ... args) {
			if (node == nullptr)
				return;

			VisitPostOrderHelper(node->Left(), func, args...);
			VisitPostOrderHelper(node->Right(), func, args...);
			func(node, args...);
		}

		TreeNode<T>* root_ = nullptr;
	};
}