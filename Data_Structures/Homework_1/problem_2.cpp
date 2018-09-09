/* Written by Michael Rogers
Student ID: 105667404
Professor Gupta
Problem 2*/

#include <iostrem>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct User {
  string username;
  float gpa;
  int age;
}

void addUser(vector<User> *users, string _username, float _gpa, int _age) {
  User string_username;
  string_username.username = string_username;
  string_username.gpa = _gpa;
  string_username.age = _age;
  vector.push_back(string_username)
}

int main(int argc, char *argv[]) {
  if(argc != 2) {
    return "Invalid number of arguments.";
  }
  else {
    fstream myFile(argv[1]);
    stringstream ss;
    string line;

    ss << line;

    while(getline(myFile,line)) {
      string item;
      getline(line,item,',') {

      }
    }


  }
}
