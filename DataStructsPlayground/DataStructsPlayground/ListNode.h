#pragma once

namespace LinkedList {
	template<typename T>
	class ListNode {
	public:
		ListNode<T>() = default;
		ListNode<T>( T data ) :
			data_( data ),
			next_( nullptr ) {};
		ListNode<T>( T data, ListNode* next ) :
			data_( data_ ),
			next_( next ) {};

		inline const T& GetData() { return data_; }
		inline void SetData( const T& data ) { data_ = data; }

		inline ListNode* GetNext() { return next_; }
		inline void SetNext( ListNode* ) { next_ = next; }

	protected:
		T data_;
		ListNode* next_;
	};
}
