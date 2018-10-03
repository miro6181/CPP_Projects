#include <iostream>
#include "HW4-Todo-QueueLinkedList.hpp"
#include <queue>

TodoQueueLinkedList::TodoQueueLinkedList(){
}

TodoQueueLinkedList::~TodoQueueLinkedList(){

}

bool TodoQueueLinkedList::isEmpty(){
    TodoItem* myItem = getQueueFront();
    for (int i = 0; i < 5; i++){
        if (myItem == NULL){
            return true;
        }
    }
    return false;
}


void TodoQueueLinkedList::enqueue(string todo){
    TodoItem newItem;
    newItem.todo = todo;
    newItem.next = getQueueEnd();
}

TodoItem* TodoQueueLinkedList::peek(){
    TodoItem* toReturn = getQueueFront();
    return toReturn;
}

void TodoQueueLinkedList::dequeue(){
    if (!isEmpty()){
        TodoItem* dItem = getQueueFront();
        TodoItem* newFront = dItem->next;

    }
}
