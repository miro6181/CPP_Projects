#include <iostream>
#include <fstream>
#include <sstream>
#include "PriorityQueue.hpp"

using namespace std;

int parent(int i) {return (i / 2);}

int left(int i) {return (i * 2);}

int right(int i) {return (i * 2 + 1);}

PriorityQueue::PriorityQueue(int queueSize) {
  PatientNode *PQArr = new PatientNode[queueSize];
} //Done But not sure

PriorityQueue::~PriorityQueue() {
  for(int i = 0; i < sizeof(priorityQueue[currentQueueSize])/sizeof(priorityQueue[0]); i++) {
    delete priorityQueue[i];
  }
} //Done But not sure

void PriorityQueue::enqueue (string _name, int _injurySeverity, int _treatmentTime) {
  PatientNode *patient = PatientNode(_name, _injurySeverity, _treatmentTime);
  priorityQueue[currentQueueSize + 1] = patient;
  currentQueueSize++;
  repairUpward(currentQueueSize);
} //Done But not sure

void PriorityQueue::dequeue() {
  delete priorityQueue[1];
  repairDownward(1);
} //Done But not sure

string PriorityQueue::peekName() {
  return priorityQueue[1].name;
} //Done But not sure

int PriorityQueue::peekInjurySeverity() {
  return priorityQueue[1].injurySeverity;
} //Done But not sure

int PriorityQueue::peekTreatmentTime() {
  return priorityQueue[1].treatmentTime;
} //Done But not sure

bool PriorityQueue::isFull() {
  int count = 0;
  for(int i = 0; i < priorityQueue.end(); i++) {
    count++;
  }
  if(count == maxQueueSize) {
    return true;
  }
  return false;
} //Done But not sure

bool PriorityQueue::isEmpty() {
  PatientNode *temp = priorityQueue[1];
  if(temp == nullptr) {
    return true;
  }
  return false;
} //Done But not sure

void PriorityQueue::repairUpward(int nodeIndex) {
  int p = parent(nodeIndex);
  if(nodeIndex == 1) {
    return;
  }
  if(priorityQueue[p].injurySeverity < priorityQueue[nodeIndex].injurySeverity) {
    PatientNode temp = priorityQueue[nodeIndex];
    priorityQueue[p] = priorityQueue[nodeIndex];
    priorityQueue[nodeIndex] = temp;
  }
  if(priorityQueue[p].injurySeverity == priorityQueue[nodeIndex].injurySeverity && priorityQueue[p].treatmentTime > priorityQueue[nodeIndex].treatmentTime) {
    //if(priorityQueue[p].treatmentTime > priorityQueue[nodeIndex].treatmentTime) {
      PatientNode temp = priorityQueue[nodeIndex];
      priorityQueue[p] = priorityQueue[nodeIndex];
      priorityQueue[nodeIndex] = temp;
    //}
  }
  repairUpward(p);
} //Not completely working correctly

void PriorityQueue::repairDownward(int nodeIndex) {
  int r = right(nodeIndex);
  int l = left(nodeIndex);
  if(nodeIndex == currentQueueSize) {
    return;
  }
  if(priorityQueue[nodeIndex].injurySeverity < priorityQueue[l].injurySeverity) {
    PatientNode temp = priorityQueue[l];
    priorityQueue[l] = priorityQueue[nodeIndex];
    priorityQueue[nodeIndex] = temp;
  }
  if(priorityQueue[nodeIndex].injurySeverity == priorityQueue[l].injurySeverity && priorityQueue[l].treatmentTime < priorityQueue[nodeIndex].treatmentTime) {
    PatientNode temp = priorityQueue[l];
    priorityQueue[l] = priorityQueue[nodeIndex];
    priorityQueue[nodeIndex] = temp;
  }
  repairDownward(l);
} //Not completely working correctly
