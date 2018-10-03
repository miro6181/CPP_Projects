#include <iostream>
#include "HW4-Todo-StackLinkedList.hpp"

TodoStackLinkedList::TodoStackLinkedList(){

}

TodoStackLinkedList::~TodoStackLinkedList(){
}

bool TodoStackLinkedList::isEmpty(){
  TodoItem* head = getStackHead();
  if (head != NULL){
        return false;
    }
  else{
        //cout << "check 2" << endl;
      return true;
  }
}

void TodoStackLinkedList::push(string toDoItem){
    TodoItem* addItem = new TodoItem;
  if (!isEmpty()){
    stackHead->todo = toDoItem;
    stackHead->next = NULL;
  }
  else{
      addItem->next = stackHead;
      addItem->todo = toDoItem;
      stackHead = addItem;
      //delete [] addItem;
  }
}

void TodoStackLinkedList::pop(){
if(!isEmpty()){
  TodoItem* head = getStackHead();
  TodoItem* newHead = head->next;
  cout << "check 3" << endl;
  newHead->next = stackHead->next->next;
  stackHead = newHead;
  }
  else{
      cout << "Stack empty, cannot pop an item." << endl;
  }
}

TodoItem* TodoStackLinkedList::peek(){
    if (isEmpty()){
        cout << "Stack empty, cannot peek." << endl;
        return NULL;
    }
    return stackHead;
}
