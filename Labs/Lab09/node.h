#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <memory>

struct Node{
  std::string name;
  Node(std::string name) : name{name}{}
  std::shared_ptr<Node> next;
  std::weak_ptr<Node> weakNext;
  
  ~Node() { std::cout << "Node [" << name << "] destructor" << std::endl; }
};

#endif