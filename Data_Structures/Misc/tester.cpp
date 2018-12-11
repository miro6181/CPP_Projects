#include <iostream>

using namespace std;

int main() {
  void calculateCost(int count, float& subTotal, float taxCost);

  void calculateCost(int count, float& subTotal, float taxCost) {
    if(count > 10) {
      subTotal = count * 0.50;
    }
    else {
      subTotal = count * 0.20;
    }
    taxCost = 0.1 * subTotal;
  }

  float tax = 0.0, subtotal = 0.0;

  calculateCost(15,subtotal,tax);
  cout << "The cost for 15 items is" << subtotal << ",and the tax for subtotal" << subtotal << "is" << tax << endl;
}
