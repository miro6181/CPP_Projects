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

node *search(int value, node *head, int &position) {
  node *current = head;
  while(current != NULL) {
    if(current->key == value) {
      return current;
    }
    current = current->next;
    position++;
  }
  return NULL;
}
int main() {

  int i = 1;
  node *head = new node(i, NULL);
  node *p = head;
  i++;
  while(i <= 10) {
    node *n = new node(i, NULL);
    p->next = n;
    p = n;
    i++;
  }
  int position = 0;
  p = search(5, head, position);
  if(p != NULL) {
    cout << "found it" << endl;
    cout << "Position of the node " << position << endl;
  }
  else {
    cout << "not in list" << endl;
  }
}
