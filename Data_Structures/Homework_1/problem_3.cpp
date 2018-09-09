/* Written by Michael Rogers
Student ID: 105667404
Professor Gupta
Problem 3*/

#include <iostream>

using namespace std;

class Movie {
  private:
    string title;
    int year;
    float rating;
  public:
    Movie(string t, int y, float r) {
      title = t;
      year = y;
      rating = r;
    }
    Movie() {
      title = "Unknown";
      year = 2018;
      rating = 0.0;
    }
    void getTitle() {
      cout << "Title: " << title << endl;
    }
    void setTitle(string t) {
      title = t;
    }
    void getYear() {
      cout << "Year: " << year << endl;
    }
    void setYear(int y) {
      if(y > 0 and y < 2019) {
        year = y;
      }
      else
        cout << "Year out of range." << endl;
    }
    void getRating() {
      cout << "Rating(0-10): " << rating << endl;
    }
    void setRating(float r) {
      if(r >= 0 and r < 11) {
        rating = r;
      }
      else
        cout << "Rating out of range." << endl;
      }
};

int main(int argc, char* argv[]) {
  Movie Avatar;
  Avatar.getTitle();
  Avatar.setTitle("Avatar");
  Avatar.getTitle();
  Avatar.getYear();
  Avatar.setYear(2009);
  Avatar.getYear();
  Avatar.getRating();
  Avatar.setRating(7.8);
  Avatar.getRating();
  cout << "\n";

  Movie Transformers;
  Transformers.getTitle();
  Transformers.setTitle("Transformers");
  Transformers.getTitle();
  Transformers.getYear();
  Transformers.setYear(2007);
  Transformers.getYear();
  Transformers.getRating();
  Transformers.setRating(7.1);
  Transformers.getRating();
  cout << "\n";

  Movie Ratatoullie;
  Ratatoullie.getTitle();
  Ratatoullie.setTitle("Ratatoullie");
  Ratatoullie.getTitle();
  Ratatoullie.getYear();
  Ratatoullie.setYear(2007);
  Ratatoullie.getYear();
  Ratatoullie.getRating();
  Ratatoullie.setRating(8);
  Ratatoullie.getRating();
}
