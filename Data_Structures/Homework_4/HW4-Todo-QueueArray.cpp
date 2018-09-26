#include <iostream>
#include "HW4-Todo-QueueArray.hpp"

using namespace std;

TodoQueueArray::TodoQueueArray() {
  queueEnd = -1;
  queueFront = -1;
  //Constructor
}

bool TodoQueueArray::isEmpty() {
  return (queueEnd == -1 && queueFront == -1);
}

bool TodoQueueArray::isFull() {
  return (queueEnd + 1)%MAX_QUEUE_SIZE == queueFront ? true : false;
}

void TodoQueueArray::enqueue(string todoItem) {
  cout << "Enqueueing: " << todoItem << endl;
  if(isFull()) {
    cout << "Error: Queue is Full";
    return;
  }
  if(isEmpty()) {
    queueFront = queueEnd = 0;
  }
  else {
    queueEnd = (queueEnd + 1)%MAX_QUEUE_SIZE;
  }
  queue[queueEnd] = todoItem;
}

void TodoQueueArray::dequeue() {
  cout << "Dequeuing \n";
  if(isEmpty()) {
    cout << "Error: Queue is Empty\n";
    return;
  }
  else if(queueFront == queueEnd) {
    queueEnd = queueFront = -1;
  }
  else {
    queueFront = (queueFront + 1)%MAX_QUEUE_SIZE;
  }
}

TodoItem TodoQueueArray::peek() {
  if(queueFront == -1) {
    cout << "Error: Cannot return front of empty queue.\n";
    return -1;
  }
  return queue[queueFront];
}

int getQueueFront() {
  return queue[queueFront];
}
int getQueueEnd() {
  return queue[queueEnd];
}

TodoItem* getQueue() {
  return queue;
}
