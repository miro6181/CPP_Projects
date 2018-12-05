#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include "CRMTree.hpp"

using namespace std;

int main() {
  cout << "Welcome!" << endl;
  cout << "Select an option from the Menu Below" << endl;
  cout << "=======Main Menu=======" << endl;
  cout << "1. Add Customer" << endl;
  cout << "2. Delete Customer" << endl;
  cout << "3. Search " << endl;
  cout << "4. Add Transaction" << endl;
  cout << "5. Exit " << endl;

  int useIn;
  cin >> useIn;

  switch(useIn) {
    case 1:
      string name;
      cout << "Enter Name " << endl;
      cin >> name;

      string email;
      cout << "Enter Email " << endl;
      cin >> email;

      string phone;
      cout << "Enter Phone Number " << endl;
      cin >> phone;

      addCustomer(name, email, phone);

    case 2:
      cout << "What customer do you want to delete?" << endl;
      string delCust;
      cin >> delCust;

      cout << "Deleting..." << endl;
      deleteCustomer(delCust);
      cout << "Customer Deleted" << endl;

    case 3:
      cout << "Enter the Customer's Name: " << endl;
      string name;
      cin >> name;

      search(name);

    case 4:
      string name;
      cout << "Enter the name of the customer: "
      cin >> name;
      custNode *customer = search(name);

      string descript;
      cout << "Enter a Description: "
      cin >> descript;

      double amount;
      cout << "Enter an amount: "
      cin >> amount;

      string currentTime = timestamp();

      string ip;
      cout << "Has the Customer Paid?(Y/N)"
      cin >> ip;

      bool isPaid
      if(ip == "Y" || ip == "y") {
        isPaid = true;
      }
      else {
        isPaid = false;
      }

      newTransaction(customer, descript, amount, isPaid);

    case 5:
      cout << "GoodBye!" << endl;
      exit;
  };
}
