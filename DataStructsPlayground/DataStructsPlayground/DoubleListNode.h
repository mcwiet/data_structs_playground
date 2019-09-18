#pragma once

namespace LinkedList {
	template<typename T>
	class DoubleListNode {
	public:
		DoubleListNode<T>() = default;
		DoubleListNode<T>( T data ) :
			data_( data ),
			next_( nullptr ),
			prev_( nullptr ) {};
		DoubleListNode<T>( T data, DoubleListNode* next, DoubleListNode* prev ) :
			data_( data_ ),
			next_( next ),
			prev_( prev ) {};

		inline const T& GetData() { return data_; }
		inline void SetData( const T& data ) { data_ = data; }

		inline DoubleListNode* GetNext() { return next_; }
		inline void SetNext( DoubleListNode* next ) { next_ = next; }

		inline DoubleListNode* GetPrev() { return prev_; }
		inline void SetPrev( DoubleListNode* prev ) { prev_ = prev; }

	protected:
		T data_;
		DoubleListNode* next_;
		DoubleListNode* prev_;
	};
}
