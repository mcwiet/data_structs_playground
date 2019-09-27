#pragma once
#include "TreeNode.h"
#include <exception>
#include <queue>

// For now, just copying and re-writing functionality as necessary from the
// BinaryTree class. Obviously more OO ways of doing it, but not my main concern here :)

// Also, our BST will follow the rule that no duplicates are allowed but will does not
// have to be a complete tree.

namespace Tree {
	class RemovingInvalidValueException : public std::exception {};

	template <typename T>
	class BinarySearchTree {
	public:
		virtual ~BinarySearchTree() {
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
			TreeNode<T>** current = &root_;
			while (*current != nullptr) {
				if (data < (*current)->Data()) {
					current = (*current)->LeftAddr();
				}
				else if (data > (*current)->Data()) {
					current = (*current)->RightAddr();
				}
				else {
					break;
				}
			}
			if (*current == nullptr) {
				*current = new TreeNode<T>(data);
			}
		};

		inline void Remove(const T& data) {
			return;
		};

		inline bool Find(const T& data) {
			return false;
		}

		inline bool IsEmpty() { return root_ == nullptr; }

		template<typename Func, typename... Args>
		void VisitInOrder(Func&& visit_func, Args&& ... args) {
			VisitInOrderHelper(root_, std::forward<Func>(visit_func), std::forward<Args>(args)...);
		}

		template<typename Func, typename... Args>
		void VisitPreOrder(Func&& visit_func, Args&& ... args) {
			VisitPreOrderHelper(root_, std::forward<Func>(visit_func), std::forward<Args>(args)...);
		}

		template<typename Func, typename... Args>
		void VisitPostOrder(Func&& visit_func, Args&& ... args) {
			VisitPostOrderHelper(root_, std::forward<Func>(visit_func), std::forward<Args>(args)...);
		}

	private:
		template<typename Func, typename... Args>
		void VisitInOrderHelper(TreeNode<T>* node, Func&& func, Args&& ... args) {
			if (node == nullptr)
				return;

			VisitInOrderHelper(node->Left(), std::forward<Func>(func), std::forward<Args>(args)...);
			func(node, args...);
			VisitInOrderHelper(node->Right(), std::forward<Func>(func), std::forward<Args>(args)...);
		}

		template<typename Func, typename... Args>
		void VisitPreOrderHelper(TreeNode<T>* node, Func&& func, Args&& ... args) {
			if (node == nullptr)
				return;

			func(node, args...);
			VisitPreOrderHelper(node->Left(), std::forward<Func>(func), std::forward<Args>(args)...);
			VisitPreOrderHelper(node->Right(), std::forward<Func>(func), std::forward<Args>(args)...);
		}

		template<typename Func, typename... Args>
		void VisitPostOrderHelper(TreeNode<T>* node, Func&& func, Args&& ... args) {
			if (node == nullptr)
				return;

			VisitPostOrderHelper(node->Left(), std::forward<Func>(func), std::forward<Args>(args)...);
			VisitPostOrderHelper(node->Right(), std::forward<Func>(func), std::forward<Args>(args)...);
			func(node, args...);
		}

		TreeNode<T>* root_ = nullptr;
	};
}