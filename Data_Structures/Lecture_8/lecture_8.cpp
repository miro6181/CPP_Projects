#include <iostream>

using namespace std;

struct node {
  int key;
  node *next;
  node(int k, node *n){
    key = k;
    next = n;
  }
};

int main() {

  int i = 1;
  node *head = new node(i, NULL);
  node *p = head; //head and p point to the same memory
  i++;
  while(i <= 10) {
    node *n = new node(i, NULL); //n->next = NULL, n->key = i
    p->next = n; //set p's next node to point to n
    p = n; //same as p = p->next
    i++;
  }
  while(head != NULL) {
    cout << head->key << endl;
    head = head->next;
  }
}
