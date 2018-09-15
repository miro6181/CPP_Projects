#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct wordItem {
  string word;
  int count;
};

//Function Prototypes
void​ ​getStopWords​(​char​ *ignoreWordFileName, ​string​ ignoreWords[]);
void​ ​arraySort​(wordItem ​list​[], ​int​ length);
void​ ​printTopN​(wordItem wordItemList[], ​int​ topN);
bool​ ​isStopWord​(​string​ word, ​string​ ignoreWords[]);
int​ ​getTotalNumberNonStopWords​(wordItem ​list​[], ​int​ length);

//Function Implementations
void​ ​getStopWords​(​char​ *ignoreWordFileName, ​string​ ignoreWords[]) {
  ifstream stopWords(ignoreWordFileName);
  if(!stopWords.is_open()) {
    cout << "Failed to open text file." << endl;
  }
  else {
    string line;
    while(getline(stopWords, line)) {
      stringstream ss;
      ss >> line;
      cout << line << endl;
    }
  }
}

void​ ​arraySort​(wordItem ​list​[], ​int​ length) {
  for(int i = 0; i < length; i++) {

  }
}

void​ ​printTopN​(wordItem wordItemList[], ​int​ topN) {

}

bool​ ​isStopWord​(​string​ word, ​string​ ignoreWords[]) {
  bool found = (find(ignoredWords.begin(), ignoreWords.end(), word) != ignoreWords.end());
  for(int i = 0; i < ignoreWords; i++){
    if(word == ignoreWords[i]) {
      return 0;
    }
  }
}

int​ ​getTotalNumberNonStopWords​(wordItem ​list​[], ​int​ length) {

}


int main(int argc, char *argv[]) {
  if(argc != 3) {
    cout << "Invalid number of arguments." << endl;
  }
  else {
    //Execute program
  }
}
