#include <iostream>
#include <fstream>
#include <sstream>
#include "PriorityQueue.hpp"

int main(int argc, char* argv[]) {
  PriorityQueue PatientDirect(argv[1]);

  while(true) {
    cout << "======Main Menu======" << endl;
    cout << "1. Get Patient Information from File" << endl;
    cout << "2. Add Patient to Priority Queue" << endl;
    cout << "3. Show Next Patient" << endl;
    cout << "4. Treat Next Patient" << endl;
    cout << "5. Treat Entire Queue" << endl;
    cout << "6. Quit" << endl;

    int use_in;
    cin >> use_in;

    if(use_in == 1) {
      cout << "Enter filename:" << endl;

      string use_file;
      cin >> use_file;

      ifstream inFile(use_file);
      string line;

      while(getline(line, use_file, " ")) {

      }
    }
    if(use_in == 2) {
      if(PatientDirect.isFull() == true){
        cout << "Priority Queue full. Send Patient to another hospital." << endl;
      }
      else {
        cout << "Enter Patient Name:" << endl;
        string pat_name;
        cin >> pat_name;
        cout << "Enter Injury Severity:" << endl;
        int inj_sev;
        cin >> inj_sev;
        cout << "Enter Treatment Time:" << endl;
        int treat_time;
        cin >> treat_time;

        enqueue(pat_name, inj_sev, treat_time);
      }
    }
    if(use_in == 3) {
      if(PatientDirect.isEmpty() == true) {
        cout << "Queue empty." << endl;
      }
      else {
        cout << "Patient Name: " << priorityQueue[1].name << endl;
        cout << "Injury Severity: " << priorityQueue[1].injurySeverity << endl;
        cout << "Treatment Time: " << priorityQueue[1].treatmentTime << endl;
      }
    }
    if(use_in == 4) {
      if(PatientDirect.isEmpty() == true) {
        cout << "Queue empty." << endl;
      }
      else {
        cout << "Patient Name: " << priorityQueue[1].name << " - Total Time Treating Patients: " << priorityQueue[1].treatmentTime << endl;
        dequeue()
      }
    }
    if(use_in == 5) {

    }
    if(use_in == 6) {
      cout << "Goodbye!" << endl;
      break;
    }
    else {
      cout << "Invalid Selection" << endl;
    }
  }
  return 0;
}
