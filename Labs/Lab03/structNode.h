#ifndef NODE_H
#define NODE_H

struct Node{
  int data;
  Node* next;
  
  // constructor
  Node(int value){
    data = value;
    next = nullptr;
  }
  
  // copy constructor
  Node(const Node& other){
    data = other.data;
    next = nullptr;
  }
  
  // destructor
  ~Node();
};

// function declarations
Node* build_linked_list(int arr[], int size);
void print_linked_list(Node* root);
void delete_entire_linked_list(Node*& root);
int get_linked_list_data_item_value(Node* root, int node_number);
void delete_list_element(Node*& root, int node_number);

#endif