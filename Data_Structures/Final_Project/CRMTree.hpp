#ifndef CRM_TREE_HPP
#define CRM_TREE_HPP
#include <string>
#include <vector>

// Struct to store all transaction info
struct Transaction {
  std::string description;
  double amount;
  std::string CurrentTime;
  bool isPaid;

  Transaction(std::string d, double a, std::string t, bool ip) {
    description = d;
    amount = a;
    CurrentTime = t;
    isPaid = ip;
  }
};

// Class to store node information
class CustNode {
public:
  CustNode(){
    parent = leftChild = rightChild = nullptr;
  }

  CustNode(std::string n, std::string e, std::string p, std::vector<Transaction> t){
    name = n;
    email = e;
    phone = p;
    parent = rightChild = leftChild = nullptr;
  }

  ~CustNode() {}
  void addTransaction(std::string description, double amount, bool isPaid);

  std::string name;
  std::string email;
  std::string phone;

  CustNode *parent;
  CustNode *rightChild;
  CustNode *leftChild;

private:
  std::vector<Transaction> tran;
};

//Class to Store Tree
class CRMTree {
public:
  CRMTree();
  ~CRMTree();
  void addCustomer(std::string name,std::string email, std::string phone);
  void deleteCustomer(std::string delCust);
  void newTransaction(CustNode newTransNode, std::string description, double amount, bool isPaid);
  void findCustomer();


private:
  CustNode *root;
  CustNode search(std::string name);
};

#endif
