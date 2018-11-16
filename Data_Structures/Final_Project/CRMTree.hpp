#ifndef CRM_TREE_HPP
#define CRM_TREE_HPP
#include <string>
#include <vector>

// Struct to store all transaction info
struct transaction {
  std::string description;
};

// Class to store node information
class CustNode {
public:
  std::string name;
  std::string email;
  std::string phone;
  void addTransaction();

  CustNode *parent;
  CustNode *rightChild;
  CustNode *leftChild;
private:
  std::vector<transaction> tran;
};

//Class to Store Tree
class CRMTree {
public:

private:
  CustNode *root;
  // Look into templates to see if this can search with name, email, or phone
  CustNode search(std::string inCust);
};

#endif
