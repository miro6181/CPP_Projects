#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class arrStack {
  public:
    arrStack();
    ~arrStack();
    bool isEmpty(); //might want to make private
    bool isFull(); //might want to make private

    int peek();
    int pop();
    bool push(int);
  private:
    int stackOInts[MAX_SIZE];
    int currentSize = 0;
};

arrStack::arrStack() {
  //constructor
}
arrStack::~arrStack() {
  //destructor
}

bool arrStack::isEmpty() {
  if(currentSize == 0) {
    return true; //no elements left, hence empty
  }
  else {
    return false;
  }
}

bool arrStack::isFull() {
  if(currentSize ==  MAX_SIZE) {
    return true;
  }
  else {
    return false;
  }
}


bool arrStack::push(int itemToAdd) {
  //if push is successful, return true
  //check if stack is is full
  if(isFull()) {
    return false;
  }
  else {
    stackOInts[currentSize] = itemToAdd;
    currentSize += 1;
    return true;
  }
}

int arrStack::pop() {
  if(!isEmpty()) {
    int itemToReturn = stackOInts[currentSize-1];
    currentSize -= 1;
    return itemToReturn;
  }
  else {
    cout << "stack is empty" << endl;
    return -999999999;
  }
}

int arrStack::peek() {
  if(!isEmpty()) {
    return stackOInts[currentSize-1];
  }
  else {
    cout << "stack is empty" << endl;
    return -999999999;
  }
}

int main() {
  arrStack stackey;
  if(!stackey.isEmpty()) {
    cout << "stack is empty" << endl;
  }
  if(stackey.push(33)) {
    cout << "33 added to stack" << endl;
  }
  stackey.pop();
  stackey.peek();
}
