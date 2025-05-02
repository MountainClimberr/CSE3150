#include "linkedList.h"
#include <iostream>

LinkedList::LinkedList(){
  names = { "zero", "one", "two", "three", "four", "five" };
  numberOfNodes = names.size();
  root = nullptr;
}

void LinkedList::SERVER_buildCircularLinkedList(){
  root = std::make_shared<Node>(names[0]);
  std::shared_ptr<Node> node = root;

  for (int i = 1; i < numberOfNodes; i++){
    node->next = std::make_shared<Node>(names[i]);
    node = node->next;
  }

  node->next = root;
  // set weak pointers
  node = root;
  do{
    node->weakNext = node->next;
    node = node->next;
  } while (node != root);
}

void LinkedList::SERVER_deleteCircularLinkedList(){
  if (!root){
    return;
  }

  std::cout << "\nServer is deleting the shared_ptrs (step 4):" << std::endl;
  // delete the circular linked list by breaking the cycle
  std::shared_ptr<Node> current = root;
  for (int i = 0; i < numberOfNodes - 1; i++){
    current = current->next;
  }

  current->next.reset();
  root.reset();
}

void LinkedList::SERVER_printLinkedList(){
  if (!root){
    std::cout << "Server: Linked list is empty" << std::endl;
    return;
  }

  std::cout << "Server (step 2):" << std::endl;

  std::shared_ptr<Node> node = root;
  do{
    std::cout << "[" << node->name << "] : use_count: " << node.use_count() << " address: " << node.get() << " next (from shared_ptr): " << node->next.get() << std::endl;
    node = node->next;
  } while (node != root);
}

void LinkedList::CLIENT_printLinkedList(){
  if (!root){
    std::cout << "\nClient after linked list deleted (step 5):" << std::endl;
    std::cout << "Client after linked list deleted:" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "[Nothing]" << std::endl;
    return;
  }

  std::cout << "\nClient (step 3):" << std::endl;

  std::shared_ptr<Node> node = root;
  int count = 0;

  do{
    std::shared_ptr<Node> nextNode = node->weakNext.lock();

    std::cout << "[" << node->name << "] : use_count: " << node.use_count() << " address: " << node.get() << " next (from weak_ptr): ";

    if (nextNode){
      std::cout << nextNode.get() << std::endl;
      node = nextNode;
    } else {
      std::cout << "0" << std::endl;
      std::cout << "Yipes! shared_ptr not available" << std::endl;
      break;
    }

    count++;
    if (count >= numberOfNodes){
      break;
    }
  } while (node != root);

  while (count < numberOfNodes - 1){
    std::cout << "Yipes! shared_ptr not available" << std::endl;
    count++;
  }
}