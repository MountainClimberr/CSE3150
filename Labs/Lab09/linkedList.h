#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <vector>
#include <memory>
#include <string>

class LinkedList{
private:
  std::shared_ptr<Node> root;
  std::vector<std::string> names;
  int numberOfNodes;
    
public:
  LinkedList();
    
  void SERVER_buildCircularLinkedList();
  void SERVER_deleteCircularLinkedList();
  void SERVER_printLinkedList();
  void CLIENT_printLinkedList();
};

#endif