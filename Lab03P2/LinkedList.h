#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {
public:
  Node * root;

  LinkedList() : root(nullptr) {}

  void insertAtBeginning(int val) {
    Node * newNode = new Node(val);
    newNode->next = root;
    root = newNode;
  }

  void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (!root) {
      root = newNode;
      return;
    }
    Node* current = root;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }

  Node * getLastElement() {
    Node * current = root;
    while (current->next) {
      current = current->next;
    }
    return current;
  }

  void deleteNode(int val) {
    if (!root) return;
    if (root->data == val) {
      Node* temp = root;
      root = root->next;
      delete temp;
      return;
    }
    Node* current = root;
    while (current->next && current->next->data != val) {
      current = current->next;
    }
    if (current->next) {
      Node* temp = current->next;
      current->next = current->next->next;
      delete temp;
    }
  }

  // function that deletes the ith node in the linked list 
  void deleteIthNode(int index){
    if(!root) return;

    if(index == 0){
      Node* temp = root;
      root = root->next;
      delete temp;
      return;
    }

    Node* current = root;
    int count = 0;

    while(current && count < index -1){
      current = current->next;
      count++;
    }

    if(!current || !current->next) return;

    Node* temp = current->next; 
    current->next = current->next->next;
    delete temp;
  }

  ~LinkedList() {
    Node* current = root;
    while (current) {
      Node* next = current->next;

      if (next == current){
        delete current;
        break;
      }
      delete current;
      current = next;
    }
    root = nullptr;
  }

  // copy constructor for the LinkedList class 
  LinkedList(const LinkedList & other){
    if(!other.root){
      root = nullptr;
      return;
    }

    root = new Node(other.root->data);
    Node* current = root;
    Node* otherCurrent = other.root->next;

    while(otherCurrent){
      current->next = new Node(otherCurrent->data);
      current = current->next;
      otherCurrent = otherCurrent->next;
    }
  }

  // function that checks if the linked list forms a positive prefix sum 
  bool isPositivePrefixSum(){
    if(!root) return false; 

    int sum = 0; 
    Node* current = root; 

    while(current){
      sum += current->data; 
      if(sum < 0) return false;
      current = current->next;
    }
    return true;
  }

  // function that checks if the linked list is a negativce prefix sum 
  bool isNegativePrefixSum(){
    if(!root) return false;

    int sum = 0; 
    Node* current = root; 

    while(current){
      sum += current->data;
      if(sum > 0) return false;
      current = current->next;
    }
    return true;
  }

  // function to preform pointer jumping on a linked list of pointers 
  void pointerJumping(){
    if(!root || !root->next) return;

    Node* lastElement = getLastElement();
    lastElement->next = lastElement;
    Node* current = root;

    while(current != lastElement){
      Node* next = current->next;
      current->next = lastElement;
      current = next;
    }
  }
};

ostream & operator<<(ostream & os, const LinkedList & linkedList) {
  Node * current = linkedList.root;
  while (current) {
    os << *current << " ";
    current = current->next;
  }
  return os;
}

#endif
