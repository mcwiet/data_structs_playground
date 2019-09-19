#include "pch.h"
#include "ListNode.h"
#include <string>

namespace LinkedListTests {
	TEST( ListNodesTests, ConstructWithData ) {
		LinkedList::ListNode<int> node1( 5 );
		LinkedList::ListNode<float> node2( -20.0F );
		LinkedList::ListNode<char> node3( 'q' );
		LinkedList::ListNode<std::string> node4( "coffee is good" );

		EXPECT_EQ( node1.GetData(), 5 );
		EXPECT_FLOAT_EQ( node2.GetData(), -20.0F );
		EXPECT_EQ( node3.GetData(), 'q' );
		EXPECT_EQ( node4.GetData(), "coffee is good" );
	}

	TEST( ListNodesTests, SetAndGetData ) {
		LinkedList::ListNode<int> node;
		node.SetData( 5 );
		EXPECT_EQ( node.GetData(), 5 );
		node.SetData( 200 );
		EXPECT_EQ( node.GetData(), 200 );
	}

	TEST( ListNodeTests, NextDefaultNullptr ) {
		LinkedList::ListNode<int> node;
		EXPECT_EQ( node.GetNext(), nullptr );
	}

	TEST( ListNodeTests, SetAndGetNextNode ) {
		LinkedList::ListNode<int> head( 5 );
		LinkedList::ListNode<int> tail( 10 );
		head.SetNext( &tail );
		LinkedList::ListNode<int>* current = &head;
		current = current->GetNext();
		EXPECT_EQ( current, &tail );
	}
}