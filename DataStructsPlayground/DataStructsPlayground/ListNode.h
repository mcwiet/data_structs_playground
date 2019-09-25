#pragma once

namespace LinkedList {
	template<typename T>
	class ListNode {
	public:
		explicit ListNode<T>() = default;
		explicit ListNode<T>(const T& data) :
			data_(data) {};
		explicit ListNode<T>(ListNode* next) :
			next_(next) {};
		explicit ListNode<T>(const T& data, ListNode* next) :
			data_(data),
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