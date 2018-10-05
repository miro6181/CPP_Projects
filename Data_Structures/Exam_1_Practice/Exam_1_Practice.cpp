/* Program 1 - Mandatroy
Write a program that creates a linked list of integers, and a function that finds the maximum value in that list.*/

// #include <iostream>
//
// using namespace std;
//
// struct node {
//   int key;
//   node *next;
//   node(int k, node *n) {
//     key = k;
//     next = n;
//   }
// };
//
// int maximum(node *head) {
//   if(head == NULL){
//     return 0;
//   }
//   else {
//     node *temp = head;
//     int max = 0;
//     while(temp != NULL) {
//       if(temp->key > max) {
//         max = temp->key;
//         temp = temp->next;
//       }
//       else {
//         temp = temp->next;
//       }
//     }
//   cout << max << endl;
//   return max;
//   }
// }
//
// int main() {
//   node *head = new node(3,NULL);
//   node *first = new node(9,NULL);
//   head->next = first;
//   node *second = new node(2,NULL);
//   first->next = second;
//   node *third = new node(4,NULL);
//   second->next = third;
//
//   maximum(head);
// }

/*Program 2 - Optional
Write a program that creates a linked list of integers, and a function that takes an index and deletes the node at that index, if it exists.*/

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

node *deleteIndex(node *head, int index) {
  node *temp = head->next;
  node *prev = head;
  int pos = 0;
  while(prev != NULL) {
    if(index == 0) {
      free(prev);
      prev = temp;
      temp = temp->next;
      head = NULL;
      return head;
    }
    if(pos == index) {
      prev->next = temp->next;
      free(temp);
      temp = prev->next;
      cout << head->key << endl;
      return head;
    }
    else {
      temp = temp->next;
      prev = prev->next;
      pos = pos + 1;
    }
  }
}

int main() {
  node *head = new node(3,NULL);
  node *first = new node(9,NULL);
  head->next = first;
  node *second = new node(2,NULL);
  first->next = second;
  node *third = new node(4,NULL);
  second->next = third;

  deleteIndex(head,0);
}
