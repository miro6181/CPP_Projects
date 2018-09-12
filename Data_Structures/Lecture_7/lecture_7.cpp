//Linked Lists

#include <iostream>

using namespace std;

struct node {
  int key;
  node *next;
  node(int k, node *n) {
    key = k;
    next = n;
  }
};

int main() {
  node *x = new node(5, NULL);
  // cout << x->key << endl;
  // cout << (*x).key << endl;

  node *x2 = new node(6,NULL);

  x->next = x2;
  // cout << x2 << endl;
  // cout << x->next << endl;

  x2->key = 10;

  node *p = x;
  while(p != NULL) {
    cout << p->key << endl;
    p = p->next;
  }
}
