// Classes and Objects

#include <iostream>

using namespace std;

class Date{
  private:
    int month;
    int day;
    int year;
  public:
    Date(int m, int d, int y){
      month = m;
      day = d;
      year = y;
    }
    void printDate(){
      cout << month << " " << day << " " << year << endl;
    }
    void setMonth(int m){
      if(m > 0 and m < 13){
        month = m;
      }
      else{
        cout << "Month out of range" << endl;
      }
    }
    void setYear(int y){
      if(y > 0 and y < 2019){
        year = y;
      }
      else{
        cout << "Year out of range" << endl;
      }
    }
    void setDate(int d){
      if(d > 0 and d < 31){
        day = d;
      }
      else{
        cout << "Day out of range" << endl;
      }
    }
};


int main(){
  Date y(28,12,2000);
  y.printDate();

  y.setMonth(12);
  y.setDate(135);
  y.printDate();
}
