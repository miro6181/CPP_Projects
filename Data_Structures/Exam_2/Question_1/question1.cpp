#include <iostream>

using namespace std;

//Struct to create nodes
struct Node {
  int key;
  Node *left, *right;
  Node(int k) {
    k = key;
    left = right = NULL;
  }
};

bool isMinHeap(Node *root){
  //Base case where we have reached the end of the tree
  if(root == NULL) {
    return true;
  }
  //While Temp != NULL search the tree
  while(root != NULL){
    isMinHeap(root->left);
    //If temp is less than each of it's children continue searching the tree
    if(root->key < root->left->key && root->key < root->right->key){
      continue;
    }
    //Else return false
    else {
      return false;
    }
    isMinHeap(root->right);
  }
  return true;
}


int main() {
  //Tree creation
  Node *root = new Node(3);
  root->left = new Node(5);
  root->right = new Node(4);
  root->right->left = new Node(9);

  isMinHeap(root);
}
