#pragma once

namespace Tree {
	template<typename T>
	class TreeNode {
	public:
		TreeNode<T>() = default;
		TreeNode<T>(T data) :
			data_(data) {};
		TreeNode<T>(TreeNode<T>* left, TreeNode<T>* right) :
			left_(left),
			right_(right) {};
		TreeNode<T>(T data, TreeNode<T>* left, TreeNode<T>* right) :
			data_(data),
			left_(left),
			right_(right) {};

		inline const T& Data() { return data_; }
		inline void Data(const T& data) { data_ = data };

		inline TreeNode<T>* Left() { return left_; }
		inline Left(TreeNode<T>* left) { left_ = left };

		inline TreeNode<T>* Right() { return right_; }
		inline Right(TreeNode<T>* right) { right_ = right; }

	private:
		T data_{};
		TreeNode<T>* left_ = nullptr;
		TreeNode<T>* right_ = nullptr;
	};
}