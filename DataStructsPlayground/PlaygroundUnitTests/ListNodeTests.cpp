#include "pch.h"
#include "ListNode.h"
#include <string>

namespace PlaygroundUnitTests {
	namespace LinkedListTests {
		TEST( ListNodeTests, ConstructWithData ) {
			LinkedList::ListNode<int> node1( 5 );
			LinkedList::ListNode<float> node2( -20.0F );
			LinkedList::ListNode<char> node3( 'q' );
			LinkedList::ListNode<std::string> node4( "coffee is good" );

			EXPECT_EQ( node1.Data(), 5 );
			EXPECT_FLOAT_EQ( node2.Data(), -20.0F );
			EXPECT_EQ( node3.Data(), 'q' );
			EXPECT_EQ( node4.Data(), "coffee is good" );
		}

		TEST( ListNodeTests, SetAndGetData ) {
			LinkedList::ListNode<int> node;
			node.Data( 5 );
			EXPECT_EQ( node.Data(), 5 );
			node.Data( 200 );
			EXPECT_EQ( node.Data(), 200 );
		}

		TEST( ListNodeTests, NextDefaultsToNullptr ) {
			LinkedList::ListNode<int> node;
			EXPECT_EQ( node.Next(), nullptr );
		}

		TEST( ListNodeTests, SetAndGetNextNode ) {
			LinkedList::ListNode<int> head;
			LinkedList::ListNode<int> tail;
			head.Next( &tail );
			LinkedList::ListNode<int>* current = &head;
			EXPECT_NE( current, &tail );
			current = current->Next();
			EXPECT_EQ( current, &tail );
		}

		TEST( ListNodeTests, ConstructWithNext ) {
			LinkedList::ListNode<int> tail;
			LinkedList::ListNode<int> head( &tail );
			EXPECT_EQ( head.Next(), &tail );
		}
	}
}