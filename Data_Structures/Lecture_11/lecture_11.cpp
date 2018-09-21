#include <iostream>

using namespace std;

const int MAX_SIZE = 2;

class Queue {
  private:
    int A[MAX_SIZE];
    int front, rear;
  public:

  Queue() {
    front = -1;
    rear = -1;
  }
  bool isEmpty() {
    return (front == -1 && rear == -1);
  }

  bool isFull() {
    return (rear+1) % MAX_SIZE == front ? true : false; //Ternary Opperator; like a one liner in Pyhton.
    /*Part before question mark is if statement condition, between colon and question mark is if
    return value and part after colon is else return value.*/
  }

  void Enqueue(int x) {
    cout << "Enqueuing" << x << " \n";
    if(isFull()) {
      cout << "Error: Queue is Full\n"
      return;
    }
    if(isEmpty()) {
      front = rear = 0;
    }
    else {
      rear = (rear+1)%MAX_SIZE;
    }
    A[rear] = x;
  }

  void Dequeue() {
    cout << "Dequeuing \n";
    if(isEmpty()) {
      cout << "Error: Queue is Empty\n";
      return;
    }
    else if(front == rear) {
      rear = front = -1;
    }
    else {
      front = (front+1)%MAX_SIZE;
    }
  }

  int Front() {
    if(front == -1) {
      cout << "Error: cannot return front from empty queue\n";
      return -1;
    }
    return A[Front];
  }

  void Print() {
    if(isEmpty()) {
      
    }
  }
}
