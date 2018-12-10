#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include "CRMTree.hpp"

using namespace std;

int main() {
  CRMTree CRM;
  cout << "Welcome!" << endl;
  cout << "Select an option from the Menu Below" << endl;
  cout << "=======Main Menu=======" << endl;
  cout << "1. Add Customer" << endl;
  cout << "2. Delete Customer" << endl;
  cout << "3. Search " << endl;
  cout << "4. Add Transaction" << endl;
  cout << "5. Exit " << endl;

  char useIn;
  cin >> useIn;

  switch(useIn) {
    case '1':
      cout << "Enter Name " << endl;
      string name;
      cin >> name;

      string email;
      cout << "Enter Email " << endl;
      cin >> email;

      cout << "Enter Phone Number " << endl;
      string phone;
      cin >> phone;

      CRM.addCustomer(name, email, phone);
      break;

    case '2':
      cout << "What customer do you want to delete?" << endl;
      string deleteCust;
      cin >> deleteCust;

      cout << "Deleting..." << endl;
      CRM.deleteCustomer(deleteCust);
      cout << "Customer Deleted" << endl;
      break;

    case '3':
      cout << "Enter the Customer's Name: " << endl;
      string name;
      cin >> name;

      CRM.search(name);
      break;

    case '4':
      string name;
      cout << "Enter the name of the customer: ";
      cin >> name;
      CustNode *customer = CRM.search(name);

      string descript;
      cout << "Enter a Description: ";
      cin >> descript;

      double amt;
      cout << "Enter an amount: ";
      cin >> amt;

      // string currentTime = timestamp();

      string ip;
      cout << "Has the Customer Paid?(Y/N)";
      cin >> ip;

      bool isPaid;
      if(ip == "Y" || ip == "y") {
        isPaid = true;
      }
      else {
        isPaid = false;
      }

      CRM.newTransaction(customer, descript, amt, isPaid);
      break;

    case '5':
      cout << "GoodBye!" << endl;
      exit;
  };
}
