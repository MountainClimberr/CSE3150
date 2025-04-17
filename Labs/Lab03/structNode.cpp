#include "structNode.h"
#include <iostream>

Node::~Node(){
  // empty destructor
}

// this function builds a new linked list from an array
Node* build_linked_list(int arr[], int size){
  if (size == 0){
    return nullptr;
  }
  Node* root = new Node(arr[0]);
  Node* current = root;
  
  for (int i = 1; i < size; i++){
    current->next = new Node(arr[i]);
    current = current->next;
  }
  
  return root;
}

// this function prints all elements in the linked list
void print_linked_list(Node* root){
  Node* current = root;
  while (current != nullptr){
    std::cout << current->data;
    if (current->next != nullptr){ 
      std::cout << " -> ";
    }
    current = current->next;
  }
  std::cout << std::endl;
}

// this function deletes the entire linked list
void delete_entire_linked_list(Node*& root){
  while (root != nullptr){
    Node* temp = root;
    root = root->next;
    delete temp;
  }
}

// this function gets the value at a specific position in the linked list
int get_linked_list_data_item_value(Node* root, int node_number){
  if (root == nullptr){
    return -1;
  }

  Node* current = root;
  int count = 1;

  while (current != nullptr && count < node_number){
    current = current->next;
    count++;
  }

  if (current == nullptr){
    return -1;
  }

  return current->data;
} 

// this function deletes an element at a specific position in the linked list
void delete_list_element(Node*& root, int node_number){
  if (root == nullptr){
    return;
  }

  if (node_number == 1){
    Node* temp = root;
    root = root->next;
    delete temp;
    return;
  }

  Node* current = root;
  Node* prev = nullptr;
  int count = 1;

  while (current != nullptr && count < node_number){
    prev = current;
    current = current->next;
    count++;
  }

  if (current != nullptr){
    prev->next = current->next;
    delete current;
  }


}