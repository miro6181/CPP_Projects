#ifndef CRM_TREE_HPP
#define CRM_TREE_HPP
#include <string>
#include <vector>

// Struct to store all transaction info
struct Transaction {
  std::string description;
  double amount;
  bool isPaid;

  Transaction(std::string d, double a, bool ip) {
    description = d;
    amount = a;
    isPaid = ip;
  }
};

// Class to store node information
struct CustNode {

  std::string name;
  std::string email;
  std::string phone;
  std::vector<Transaction> tran;

  CustNode *parent;
  CustNode *rightChild;
  CustNode *leftChild;

  CustNode(){
    parent = leftChild = rightChild = nullptr;
  }

  CustNode(std::string n, std::string e, std::string p){
    name = n;
    email = e;
    phone = p;
    parent = rightChild = leftChild = nullptr;
  }
};

//Class to Store Tree
class CRMTree {
public:
  CRMTree();
  ~CRMTree();
  void addCustomer(std::string name,std::string email, std::string phone);
  void deleteCustomer(std::string Custname);
  void newTransaction(std::string name, std::string description, double amount, bool isPaid);
  void findCustomer(std::string name);


private:
  CustNode *search(std::string name);
  CustNode *root;
};
#endif
