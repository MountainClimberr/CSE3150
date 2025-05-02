#include "node.h"
#include "linkedList.h"
#include <cassert>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Basic functionality tests") {
  // test node creation
  std::shared_ptr<Node> node1 = std::make_shared<Node>("test1");
  
  {
    std::shared_ptr<Node> node2 = std::make_shared<Node>("test2");
    
    // connect node with shared_ptr
    node1->next = node2;
    
    // connect node with weak_ptr
    node1->weakNext = node1->next;
    
    // test node properties
    CHECK(node1->name == "test1");
    CHECK(node1->next->name == "test2");
    CHECK(node1->weakNext.lock() == node2);
    
    // test node deletion 
    std::weak_ptr<Node> weakPtr = node2;
    CHECK(!weakPtr.expired());
    
    node1->next.reset();
    node2.reset();
    
    // test weak_ptr should be expired
    CHECK(weakPtr.expired());
  }
  
  // test linked list creation
  LinkedList list;
  list.SERVER_buildCircularLinkedList();
  list.SERVER_deleteCircularLinkedList();
}