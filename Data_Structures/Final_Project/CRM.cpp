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

CustNode::CustNode(std::string n, std::string e, std::string p, std::vector<Transaction> t) {
  name = n;
  email = e;
  phone = p;
  parent = rightChild = leftChild = nullptr;
} // Done

CustNode::~CustNode() {

}

void CustNode::addTransaction(std::string description, double amount) {

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

void CRMTree::addCustomer(std::string name,std::string email, std::string phone) {
  
}

void CRMTree::deleteCustomer(CustNode delCust) {

}

void CRMTree::newTransaction(CustNode newTransNode, std::string description, double amount) {

}

void CRMTree::findCustomer() {

}

CustNode CRMTree::search(CustNode inCust) {

}
