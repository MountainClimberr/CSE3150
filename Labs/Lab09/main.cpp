#include "linkedList.h"
#include <iostream>

int main(){
  LinkedList list;
  
  // step 1
  list.SERVER_buildCircularLinkedList();
  
  // step 2
  list.SERVER_printLinkedList();
  
  // step 3
  list.CLIENT_printLinkedList();
  
  // step 4
  list.SERVER_deleteCircularLinkedList();
  
  // step 5
  list.CLIENT_printLinkedList();
  
  return 0;
}