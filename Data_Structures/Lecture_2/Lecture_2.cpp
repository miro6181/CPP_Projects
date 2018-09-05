#include <iostream>
#include <fstream> //File Stream, used for reading files
#include <sstream> //String Stream put lines ins strings

using namespace std;

struct Student{
  int ID;
  string name;
  string major;
  Student(){}
  Student(int id, string n, string m){
    ID = id;
    name = n;
    major = m;
  }
};

int main(){
  Student s;
  s.ID = 5;
  s.name = "bob";
  s.major = "skiing";
  Student s2(6, "jimmy", "swimming");
  cout << s.ID << " " << s.name << " " << s.major << endl;
  cout << s2.ID << " " << s2.name << " " << s2.major << endl;
}
