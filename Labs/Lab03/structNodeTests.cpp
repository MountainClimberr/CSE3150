// linkedListTests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "structNode.h"

TEST_CASE("Testing Node construction and basic operations"){
  SUBCASE("single node creation"){
    Node* node = new Node(5);
    CHECK(node->data == 5);
    CHECK(node->next == nullptr);
    delete node;
  }

  SUBCASE("build list test"){
    int arr[] = {1, 2, 3};
    Node* list = build_linked_list(arr, 3);
    
    CHECK(list != nullptr);
    CHECK(list->data == 1);
    CHECK(list->next->data == 2);
    CHECK(list->next->next->data == 3);
    CHECK(list->next->next->next == nullptr);
    
    delete_entire_linked_list(list);
  }
}

TEST_CASE("Testing get_linked_list_data_item_value"){
  SUBCASE("empty list"){
    Node* list = nullptr;
    CHECK(get_linked_list_data_item_value(list, 1) == -1);
  }

  SUBCASE("valid positions"){
    int arr[] = {10, 20, 30};
    Node* list = build_linked_list(arr, 3);
    
    CHECK(get_linked_list_data_item_value(list, 1) == 10);
    CHECK(get_linked_list_data_item_value(list, 2) == 20);
    CHECK(get_linked_list_data_item_value(list, 3) == 30);
    
    delete_entire_linked_list(list);
  }
}

TEST_CASE("Testing delete_list_element"){
  SUBCASE("delete first element"){
    int arr[] = {1, 2, 3};
    Node* list = build_linked_list(arr, 3);
    
    delete_list_element(list, 1);
    CHECK(list->data == 2);
    CHECK(list->next->data == 3);
    
    delete_entire_linked_list(list);
  }

  SUBCASE("delete middle element"){
    int arr[] = {1, 2, 3};
    Node* list = build_linked_list(arr, 3);
    
    delete_list_element(list, 2);
    CHECK(list->data == 1);
    CHECK(list->next->data == 3);
    
    delete_entire_linked_list(list);
  }
}