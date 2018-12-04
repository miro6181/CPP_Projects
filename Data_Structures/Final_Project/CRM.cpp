#include <iostream>
#include "CRMTree.hpp"

using namespace std;

//Helper Functions
void deleteTree(CRMTree *root) {

}
// CustNode Memeber Functions
CustNode::CustNode() {
  parent = rightChild = leftChild = nullptr;
} // Done

CustNode::CustNode(string n, string e, string p, vector<Transaction> t) {
  name = n;
  email = e;
  phone = p;
  parent = rightChild = leftChild = nullptr;
} // Done

CustNode::~CustNode() {

}

void CustNode::addTransaction(string description, double amount,  bool isPaid) {

}

// CRMTree Member Functions

//Constructor
CRMTree::CRMTree() {
  root = NULL;
} // Done

//Destructor
CRMTree::~CRMTree() {
  deleteTree(root);
} // Done

void CRMTree::addCustomer(string name,string email, string phone) {

}

void CRMTree::deleteCustomer(CustNode delCust) {

}

void CRMTree::newTransaction(CustNode newTransNode, string description, double amount) {

}

void CRMTree::findCustomer() {

}

CustNode CRMTree::search(string name) {

}
