#include <iostream>
#include <time.h>
#include "CRMTree.hpp"

using namespace std;

void deleteTree(CustNode *root) {
  while(root != NULL) {
    deleteTree(root->leftChild);
    deleteTree(root->rightChild);
    delete root;
  }
} //Done

/* CustNode Memeber Functions */

void CustNode::addTransaction(string description, double amount, string t,  bool isPaid) {
  tran.push_back(Transaction(description, amount, t, isPaid))
} // Ask about timestamp

/* CRMTree Member Functions */

//Constructor
CRMTree::CRMTree() {
  root = NULL;
} // Done

//Destructor
CRMTree::~CRMTree() {
  deleteTree(root);
} // Done

void CRMTree::addCustomer(string name,string email, string phone) {

  //Create new node
  CustNode *newCustomer(string name, string email, string phone);

  //If tree is empty add at root
  if(root == NULL) {
    root = newCustomer;
  }
  else {
    //Temp node for traversal
    CustNode *temp = root;
    while(true) {
      //If left child is empty and less than temp add left
      if(newCustomer->name <= temp->name) {
        if(temp->leftChild == NULL) {
          temp->leftChild = newCustomer;
          newCustomer->parent = temp;
          return;
        }
        else {
          //Increment
          temp = temp->leftChild;
        }
      }
      else {
        //If right child is empty and less than temp add right
        if(temp->rightChild == NULL) {
          temp->rightChild = newCustomer;
          newCustomer->parent = temp;
          return;
        }
        else {
          //Increment
          temp = temp->rightChild;
        }
      }
    }
  }
} // Done

void CRMTree::deleteCustomer(CustNode delCust) {

}

void CRMTree::newTransaction(CustNode newTransNode, string description, double amount) {

}

void CRMTree::findCustomer() {
  CustNode *foundCust = search(string name);
  if(foundCust != NULL) {
    cout << "Name: " << foundCust->name << endl;
    cout << "==================" << endl;
    cout << "Email: " << foundCust->email << endl;
    cout << "Phone Number: " << foundCust->phone << endl;
    //Itterates through the transaction list and displays all of them.
    for(int i = 0; i < foundCust->tran.size(); i++) {
      cout << "Transaction " << i << ": " << foundCust->tran[i]->description << endl;
      cout << "Amount" << ": " << foundCust->tran[i]->amount << endl;
      cout << "Transaction Time" << ": " << foundCust->tran[i]->currentTime << endl;
      cout << "Is Paid" << ": " << foundCust->tran[i]->isPaid << endl;
    }
  }
}

CustNode CRMTree::search(string name) {

}
