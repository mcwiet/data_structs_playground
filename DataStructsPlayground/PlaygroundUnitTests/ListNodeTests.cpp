#include "pch.h"
#include "ListNode.h"
#include <string>

namespace LinkedListTests {
	TEST( ListNodesTests, ConstructWithData ) {
		LinkedList::ListNode<int> node1( 5 );
		LinkedList::ListNode<float> node2( -20.0F );
		LinkedList::ListNode<char> node3( 'q' );
		LinkedList::ListNode<std::string> node4( "coffee is good" );

		EXPECT_EQ( node1.Data(), 5 );
		EXPECT_FLOAT_EQ( node2.Data(), -20.0F );
		EXPECT_EQ( node3.Data(), 'q' );
		EXPECT_EQ( node4.Data(), "coffee is good" );
	}

	TEST( ListNodesTests, SetAndData ) {
		LinkedList::ListNode<int> node;
		node.Data( 5 );
		EXPECT_EQ( node.Data(), 5 );
		node.Data( 200 );
		EXPECT_EQ( node.Data(), 200 );
	}

	TEST( ListNodeTests, NextDefaultNullptr ) {
		LinkedList::ListNode<int> node;
		EXPECT_EQ( node.Next(), nullptr );
	}

	TEST( ListNodeTests, SetAndNextNode ) {
		LinkedList::ListNode<int> head( 5 );
		LinkedList::ListNode<int> tail( 10 );
		head.Next( &tail );
		LinkedList::ListNode<int>* current = &head;
		current = current->Next();
		EXPECT_EQ( current, &tail );
	}
}