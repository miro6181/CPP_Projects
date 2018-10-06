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

bool lengthIsEven(node *head) {
  int count = 0; //Set the counter to 0
  node *current = head; //Create a traversal node
  while(current != NULL) {
    if(current->key % 2 == 0) { //If divisible by 2(even) increment the counter
      count = count + 1;
      current = current->next;//Move to next node
    }
    else {
      current = current->next;//Move to next node without incrementing
    }
  }
  if(count % 2 == 0) {
    cout << "True" << endl; //For purpose of output
    return true; //If length of LL is even return true
  }
  else {
    cout << "False" << endl; //For purpose of output
    return false; //Else return false
  }
}

int main() { //Create the LL
//Should return True
  node *head = new node(3,NULL);
  node *first = new node(9,NULL);
  head->next = first;
  node *second = new node(2,NULL);
  first->next = second;
  node *third = new node(4,NULL);
  second->next = third;

  lengthIsEven(head);

//Comment out first block and uncomment this to test a case that should return False

  // node *head = new node(3,NULL);
  // node *first = new node(9,NULL);
  // head->next = first;
  // node *second = new node(2,NULL);
  // first->next = second;
  // node *third = new node(4,NULL);
  // second->next = third;
  // node *fourth = new node(10,NULL);
  // third->next = fourth;
  //
  // lengthIsEven(head);
}
