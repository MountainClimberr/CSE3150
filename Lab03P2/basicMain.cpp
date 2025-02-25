#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
  LinkedList ll, ll_1;

  cout << ll_1 << endl;

  ll.insertAtBeginning(-1);
  ll.insertAtBeginning(+1);
  ll.insertAtBeginning(-1);

  cout << ll << endl;

  ll.insertAtEnd(-44);

  cout << "-------------" << endl;

  Node *ptr_last = ll.getLastElement();

  cout << *ptr_last << endl;

  cout << "-------------" << endl;

  ll_1.insertAtBeginning(1);
  ll_1.insertAtBeginning(-1);
  ll_1.insertAtBeginning(1);
  cout << ll_1 << endl;
  ll_1.deleteNode(-1);
  cout << ll_1 << endl;

  LinkedList ll_2 = ll_1;
  ll_1.deleteNode(-1);

  cout << "-------------" << endl;

  // Test DeleteIthNode function 
  cout << "Test deleteIthNode: " << endl;
  LinkedList ll_3;
  ll_3.insertAtBeginning(-1);
  ll_3.insertAtBeginning(+1);
  ll_3.insertAtBeginning(-1);
  cout<< "Before deleteIthNode: " << ll_3 << endl;
  ll_3.deleteIthNode(1);
  cout << "After deleteIthNode: " << ll_3 << endl;

  cout << "-------------" << endl;

  // Test isPositivePrefixSum function
  cout << "Test isPositivePrefixSum: " << endl;
  LinkedList ll_4;
  ll_4.insertAtBeginning(2);
  ll_4.insertAtBeginning(3);
  ll_4.insertAtBeginning(-1);
  cout << "List: " << ll_4 << endl;
  cout << "Is Positive PrefixSum? " << (ll_4.isPositivePrefixSum() ? "Yes" : "No") << endl;

  cout << "-------------" << endl;

  // Test isNegativePrefixSum function
  cout << "Test isNegativePrefixSum: " << endl;
  LinkedList ll_5;
  ll_5.insertAtBeginning(-1);
  ll_5.insertAtBeginning(+1);
  ll_5.insertAtBeginning(-1);

  cout << "List: " << ll_5 << endl;
  cout << "Is Negative PrefixSum? " << (ll_5.isNegativePrefixSum() ? "Yes" : "No") << endl;

  cout << "-------------" << endl; 

  // Test pointerJumping function
  cout << "Test pointerJumping: " << endl;
  LinkedList ll_6;
  ll_6.insertAtBeginning(-1);
  ll_6.insertAtBeginning(+1);
  ll_6.insertAtBeginning(-1);

  cout << "Before pointerJumping: " << ll_6 << endl;
  cout << "Last element: " << *ll_6.getLastElement() << endl;

  ll_6.pointerJumping();

  // Node* lastNode = ll_6.getLastElement();
  // cout << "Last node: " << *lastNode << " next -> " << lastNode << endl;
  cout << "First node now points to: " << *ll_6.root->next << endl;
  cout << "Does first node point to last node? " << (ll_6.root->next == ll_6.root->next ? "Yes" : "No") << endl;

  cout << "Second node now points to: " << *ll_6.root->next->next << endl;
  cout << "Does second node point to last node? " << (ll_6.root->next->next == ll_6.root->next ? "Yes" : "No") << endl;

  cout << "-------------" << endl;

  return 0;
}
