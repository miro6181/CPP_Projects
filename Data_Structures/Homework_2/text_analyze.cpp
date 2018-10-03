#include <iostream>
#include <fstream>

using namespace std;

struct wordItem {
  string word;
  int count;
};

//Function Implementations
void getStopWords(char* ignoreWordFileName, string ignoreWords[]){
  ifstream wordStream;
  string line;
  int i = 0;

  wordStream.open(ignoreWordFileName);
  while (getline(wordStream, line)){
    ignoreWords[i] = line;
    i++;
  }
}

void arraySort(wordItem list[], int length){
    bool sorted = false;
    for (int j = 0; j < 20; j++){
        for (int i = 0; i < length; i++){
            int p = list[i].count;
            int q = list[i+1].count;
            wordItem a = list[i];
            wordItem b = list[i+1];

            if (q > p){
                list[i] = b;
                list[i+1] = a;
                i = 0;
            }
        }
    }
}

void printTopN(wordItem wordItemList[], int topN){
    for (int i = 0; i < topN; i++){
        cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
    }
    cout << "#" << endl;
}

bool isStopWord(string word, string ignoreWords[]){
  for (int i = 0; i < 50; i++){
    if (word == ignoreWords[i]){
      return true;
    }
  }
  return false;
}

int getTotalNumberNonStopWords(wordItem list[], int length){
    int sum = 0;
    for (int i = 0; i <= length; i++){
        sum = sum + list[i].count;
    }
    return sum;
}

int* getBiggerArray(int *oldArray, int oldCap){
  int* newArray = new int[2*oldCap];

  for (int i = 0; i < oldCap; i++){
    newArray[i] = oldArray[i];
  }
  delete [] oldArray;
  return newArray;
}


int main(int argc, char *argv[]) {
  if(argc != 4) {
    cout << "Invalid number of arguments." << endl;
  }
  else {
    int capacity = 100;
    int size = 0;
    string ignoreArray[50];
    string *mainArray = new wordItem[capacity];
    getStopWords(argv[3], ignoreArray);

    ifstream mainFile;
    string word;

    mainFile.open(argv[2]);

    while(mainFile >> word) {
      if(isStopWord(word, ignoreArray)) {
        NULL;
      }
      else {

      }
    }
  }
}
