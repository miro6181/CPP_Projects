#include <iostream>
#include "HW4-Todo-StackArray.hpp"

using namespace std;

TodoStackArray::TodoStackArray(){

}

bool TodoStackArray::isFull(){
//cout << "!!!check full" << endl;
    for (int i = 0; i < MAX_STACK_SIZE; i++){
        if (stack[i].todo == ""){
            return false;
        }
    }
    return true;
}

bool TodoStackArray::isEmpty(){
cout << "!!!check empty" << endl;
    int k = 0;
    for (int i = 0; i < MAX_STACK_SIZE; i++){
        if (stack[i].todo == ""){
            k++;
        }
    }
    if (k == MAX_STACK_SIZE){
        return true;
    }
    return false;
}

void TodoStackArray::push(string toDoItem){
    //cout << "!!!check push" << endl;
    TodoItem newItem;
    TodoItem temp[MAX_STACK_SIZE];
    newItem.todo = toDoItem;
  if(!isFull()){
    for (int i = 0; i < MAX_STACK_SIZE; i++){
        temp[i] = stack[i];
    }
    for (int j = 1; j < MAX_STACK_SIZE; j++){
        stack[0] = newItem;
        stack[j] = temp[j - 1];
    }
  }
  else{
      cout << "Stack full, cannot add new todo item." << endl;
  }
}

void TodoStackArray::pop(){
    TodoItem temp[MAX_STACK_SIZE];
    //cout << "!!!check pop" << endl;
    if (isEmpty()){
        cout << "Stack empty, cannot pop an item." << endl;
    }
    else{
        for (int u = 0; u < MAX_STACK_SIZE; u++){
            temp[u] = stack[u];
        }
        for (int v = 0; v < MAX_STACK_SIZE; v++){
            stack[v] = temp[v+1];
        }
    }
}

TodoItem TodoStackArray::peek(){
    //cout << "!!!check peek" << endl;
    TodoItem fml;
  if (!isEmpty()){
    //fml = getStackTop();
  }
  else{
    fml = stack[4];
  }
  return fml;
}
