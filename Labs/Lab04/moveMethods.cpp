#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include "LinkedList.h"

using namespace std;

TEST_CASE("Linked List Move Methods Test"){
  SUBCASE("Move Constructor"){
    LinkedList sourceList;
    sourceList.insertAtBeginning(3);
    sourceList.insertAtBeginning(2);
    sourceList.insertAtBeginning(1);
    
    LinkedList movedList(std::move(sourceList));
    
    // check that the moved list has the elements
    CHECK(movedList.root != nullptr);
    CHECK(movedList.root->data == 1);
    CHECK(movedList.root->next->data == 2);
    CHECK(movedList.root->next->next->data == 3);
    
    // check that the source list is empty
    CHECK(sourceList.root == nullptr);
  }

  SUBCASE("Move Copy Constructor"){
    LinkedList sourceList;
    sourceList.insertAtBeginning(3);
    sourceList.insertAtBeginning(2);
    sourceList.insertAtBeginning(1);
    
    LinkedList destList;
    destList.insertAtBeginning(-3);
    destList.insertAtBeginning(-2);
    destList.insertAtBeginning(-1);
    
    destList = std::move(sourceList);
    
    // check that the destination list has the source elements
    CHECK(destList.root != nullptr);
    CHECK(destList.root->data == 1);
    CHECK(destList.root->next->data == 2);
    CHECK(destList.root->next->next->data == 3);
    
    // check that the source list is empty
    CHECK(sourceList.root == nullptr);
  }

  SUBCASE("Self-Move Copy Constructor"){
    LinkedList list;
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);
    
    // get a pointer to the root node before self-move
    Node* originalRoot = list.root;
    
    // test self-move copy constructor
    list = std::move(list);
    
    // check that the list remains unchanged
    CHECK(list.root == originalRoot);
    CHECK(list.root->data == 1);
    CHECK(list.root->next->data == 2);
    CHECK(list.root->next->next->data == 3);
  }
}

// main function for doctest
int main(int argc, char** argv){
  doctest::Context context;
  context.applyCommandLine(argc, argv);
  return context.run();
}