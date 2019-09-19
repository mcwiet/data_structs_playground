#pragma once

#include "ListNode.h"

namespace LinkedList {
	template <typename T>
	class List {
	public:
		List<T>() = default;
		List<T>( ListNode<T>* head ) :
			head_( head )
		{
			if (head_ != nullptr) {
				ListNode* curr = head_;
				ListNode* next = curr->GetNext();
				while (next != nullptr) {
					curr = next;
					next = curr->GetNext();
				}
				tail_ = curr;
			}
		}

		virtual ~List<T>() {
			ListNode* curr = head_;
			ListNode* next;
			while (curr != nullptr) {
				next = curr->GetNext();
				delete curr;
				curr = next;
			}
		}

	private:
		ListNode<T>* head_;
		ListNode<T>* tail_;
	};
}