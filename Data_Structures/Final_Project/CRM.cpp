#include <iostream>
#include <time.h>
#include "CRMTree.hpp"

using namespace std;

void deleteTree(CustNode *root) {
  //Loop through and delete every node
  while(root != NULL) {
    deleteTree(root->leftChild);
    deleteTree(root->rightChild);
    delete root;
  }
} //Done

/* CRMTree Member Functions */

//Constructor
CRMTree::CRMTree() {
  root = NULL;
} // Done

//Destructor
CRMTree::~CRMTree() {
  deleteTree(root);
} // Done

CustNode* CRMTree::search(string name) {

  CustNode* searchCust = root;

  //If node's name matches return the node
  while(searchCust != NULL) {
    if(searchCust->name > name) {
      searchCust = searchCust->leftChild;
    }
    else if(searchCust->name == name){
      break;
    }
    else if(searchCust->name < name) {
      searchCust = searchCust->rightChild;
    }
  }
  return searchCust;
} //Done

void CRMTree::addCustomer(string name, string email, string phone) {

  //Create new node
  CustNode* newCust = new CustNode(name, email, phone);

  //If tree is empty add at root
  if(root == NULL) {
    root = newCust;
    return;
  }
  else {
    //Temp node for traversal
    CustNode* temp = root;
    while(temp!= NULL) {
      //If left child is empty and less than temp add left
      if(newCust->name <= temp->name) {
        if(temp->leftChild == NULL) {
          temp->leftChild = newCust;
          newCust->parent = temp;
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
          temp->rightChild = newCust;
          newCust->parent = temp;
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

void CRMTree::deleteCustomer(string Custname) {
  CustNode *delCust = search(Custname);

  // Node with only one child or no child
  if (delCust->leftChild == NULL) {
      CustNode *temp = root->rightChild;
      free(delCust);
      return;
  }
  else if (delCust->rightChild == NULL)
  {
      CustNode *temp = root->leftChild;
      free(delCust);
      return;
  }

  CustNode* current = delCust;
  // loop down to find the leftmost leaf
  while (current->leftChild != NULL)
      current = current->leftChild;

  //Replace with leftmost leaf
  delCust = current;

  // delCust->rightChild = deleteCustomer(delCust->rightChild->name);

  return;

} //Done

void CRMTree::newTransaction(string name, string description, double amount, bool isPaid) {
  CustNode* foundNode = search(name);
  foundNode->tran.push_back(Transaction(description, amount, isPaid));
} //Done

void CRMTree::findCustomer(string name) {
  CustNode* foundCust = search(name);
  if(foundCust != NULL) {
    cout << "Name: " << foundCust->name << endl;
    cout << "==================" << endl;
    cout << "Email: " << foundCust->email << endl;
    cout << "Phone Number: " << foundCust->phone << endl;
    cout << endl;
    cout << "Transactions" << endl;
    cout << "==================" << endl;
    cout << endl;
    //Itterates through the transaction list and displays all of the transactions.
    for(int i = 0; i < foundCust->tran.size(); i++) {
      cout << "Transaction " << i + 1 << ": " << foundCust->tran[i].description << endl;
      cout << "Amount" << ": " << foundCust->tran[i].amount << endl;
      cout << "Is Paid" << ": " << foundCust->tran[i].isPaid << endl;
      cout << endl;
    }
  }
} //Not Done
