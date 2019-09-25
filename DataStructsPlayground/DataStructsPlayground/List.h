#pragma once

#include "ListNode.h"
#include <exception>

namespace LinkedList {
	class EmptyListException : public std::exception {};

	template <typename T>
	class List {
	public:
		virtual ~List() {
			ListNode<T>* curr = head_;
			ListNode<T>* next;
			while (curr != nullptr) {
				next = curr->Next();
				delete curr;
				curr = next;
			}
		}

		inline void AppendBack(T data) {
			auto node = new ListNode<T>(data);
			if (head_ != nullptr) {
				tail_->Next(node);
				tail_ = tail_->Next();
			}
			else {
				head_ = node;
				tail_ = node;
			}
		}

		inline T PopFront() {
			if (IsEmpty()) {
				throw EmptyListException();
			}

			auto node = head_;
			auto data = node->Data();
			if (head_ != tail_) {
				head_ = head_->Next();
			}
			else {
				head_ = nullptr;
				tail_ = nullptr;
			}
			delete node;
			return data;
		}

		inline bool IsEmpty() {
			return ((head_ == nullptr) && (tail_ == nullptr));
		}

		inline bool Find(const T& data) {
			bool found = false;
			ListNode<T>* curr = head_;
			ListNode<T>* next;
			while (curr != nullptr) {
				next = curr->Next();
				if (curr->Data() == data) {
					found = true;
					break;
				}
				curr = next;
			}
			return found;
		}

	private:
		ListNode<T>* head_ = nullptr;
		ListNode<T>* tail_ = nullptr;
	};
}