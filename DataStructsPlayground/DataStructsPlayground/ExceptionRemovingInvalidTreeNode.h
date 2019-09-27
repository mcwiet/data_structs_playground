#pragma once
#include <exception>

namespace Tree {
	class ExceptionRemovingInvalidTreeNode : public std::exception {};
}