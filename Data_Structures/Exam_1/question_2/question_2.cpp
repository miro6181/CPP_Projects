#include <iostream>

using namespace std;

//Struct that creates the nodes
struct node {
  int key;
  node *next;
  node(int k, node *n) {
    key = k;
    next = n;
  }
};

node *deleteNegatives(node *head) {
  node *current = head; //Create traversal node
  while(current != NULL) {
    if(head->key < 0) { //Head node is negative case
      current = head->next; //Move current to second node
      delete head;//Delete Head
      head = current;//Move head to second node
    }
    else if(current->next->key < 0) { //If next key is less than 0
      current->next = current->next->next; //Point current node to node after node to be deleted
      delete current->next;//Delete the next node
      current = current->next;//Move current to the next node
    }
    else {
      current = current->next; //If not negative increment current
    }
  }
  return head;//Return head
}

int main() { //Create the LL
//Should not delete anything
  node *head = new node(3,NULL);
  node *first = new node(9,NULL);
  head->next = first;
  node *second = new node(2,NULL);
  first->next = second;
  node *third = new node(4,NULL);
  second->next = third;

  deleteNegatives(head);

  cout << head->key << " -> " << head->next->key << " -> " << head->next->next->key << " -> " << head->next->next->next->key << endl;

//Comment out first block and uncomment this to test a case that should change
//-3 -> 9 -> 2 -> 4 -> -10 -> NULL to 9 -> 2 -> 4 -> NULL

  // node *head = new node(-3,NULL);
  // node *first = new node(9,NULL);
  // head->next = first;
  // node *second = new node(2,NULL);
  // first->next = second;
  // node *third = new node(4,NULL);
  // second->next = third;
  // node *fourth = new node(-10,NULL);
  // third->next = fourth;
  //
  // deleteNegatives(head);
  //
  // //Output
  // cout << head->key << " -> " << head->next->key << " -> " << head->next->next->key << endl;
}
