#include <iostream>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include "CRMTree.hpp"

using namespace std;

int main() {
  CRMTree CRM; //Comment this line out to mess around with menu

  // Create variables for user input
  int useIn = 0;
  double amt = 0;
  bool isPaid = false;
  string name, email, phone, deleteCust, descript, ip;

  //Do while loop to manage the menu
  do {
    cout << "Welcome!" << endl;
    cout << "Select an option from the Menu Below" << endl;
    cout << "=======Main Menu=======" << endl;
    cout << "1. Add Customer" << endl;
    cout << "2. Delete Customer" << endl;
    cout << "3. Search " << endl;
    cout << "4. Add Transaction" << endl;
    cout << "5. Exit " << endl;
    cin >> useIn;
    cout << endl;

    switch(useIn) {
      case 1:
        cout << "Enter Name " << endl;
        cin >> name;
        cout << endl;

        cout << "Enter Email " << endl;
        cin >> email;
        cout << endl;

        cout << "Enter Phone Number " << endl;
        cin >> phone;
        cout << endl;

        CRM.addCustomer(name, email, phone); //Comment this line out to mess around with menu
        //Usleep is an artificial way of slowing down the program to make it flow a little better
        //This command will make the program wait 1 second before proceeding.
        usleep(1000000);
        cout << "Customer added." << endl;

        cout << endl;
        break;

      case 2:
        cout << "What customer do you want to delete?" << endl;
        cin >> deleteCust;
        cout << endl;

        cout << "Deleting..." << endl;
        CRM.deleteCustomer(deleteCust); //Comment this line out to mess around with menu
        usleep(1000000);
        cout << endl;
        cout << "Customer Deleted" << endl;

        cout << endl;
        break;

      case 3:
        cout << "Enter the Customer's Name: " << endl;
        cin >> name;
        cout << endl;

        CRM.findCustomer(name); //Comment this line out to mess around with menu

        cout << endl;
        break;

      case 4:
        cout << "Enter the name of the customer: " << endl;
        cin >> name;
        cout << endl;

        cout << "Enter a Description: " << endl;
        cin >> descript;
        cout << endl;

        cout << "Enter an amount: " << endl;
        cin >> amt;
        cout << endl;

        cout << "Has the Customer Paid?(Y/N)" << endl;
        cin >> ip;
        cout << endl;

        bool isPaid;
        if(ip == "Y" || ip == "y") {
          isPaid = true;
        }
        else {
          isPaid = false;
        }

        CRM.newTransaction(name, descript, amt, isPaid); //Comment this line out to mess around with menu

        cout << "Transaction Added." << endl;
        cout << endl;

        cout << endl;
        break;

      case 5:
        cout << "GoodBye!" << endl;

        cout << endl;
        break;

      default:
        cout << "Please Enter a valid choice." << endl;

        cout << endl;
        continue;
    }
  }
  while(useIn != 5);
    return 0;
}
