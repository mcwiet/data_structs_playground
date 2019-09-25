#pragma once

namespace LinkedList {
	template<typename T>
	class ListNode {
	public:
		ListNode<T>() = default;
		ListNode<T>(T data) :
			data_(data) {};
		ListNode<T>(ListNode* next) :
			next_(next) {};
		ListNode<T>(T data, ListNode* next) :
			data_(data_),
			next_(next) {};

		inline const T& Data() { return data_; }
		inline void Data(const T& data) { data_ = data; }

		inline ListNode* Next() { return next_; }
		inline void Next(ListNode* next) { next_ = next; }

	protected:
		T data_{};
		ListNode* next_ = nullptr;
	};
}