#include <iostream>
#include <fstream>
#include <ssteam>
#include "HashTable.hpp"

using namespace std;

HashTable::HashTable(int hashTableSize) {

}

HashTable::~HashTable() {

}

void HashTable::getStopWords(char *ignoreWordFileName) {
  ifstream inFile(ignoreWordFileName);
  if(inFile.is_open()) {
    string line;
    while(getline(inFile, line)) {
      stringstream ss;
      ss << line;
      string item;
      getline(ss,item);
      vecIgnoreWords.push_back(line);
    }
  }
} //Done

bool HashTable::isStopWord(string word) {
  for(int i = 0; i < STOPWORD_LIST_SIZE; i++) {
    if(word == vecIgnoreWords[i]){
      return true;
    }
    else {
      continue;
    }
  }
  return false;
} //Done

bool HashTable::isInTable(string word) {

}

void HashTable::incrementCount(string word) {

}

void HashTable::addWord(std::string word) {
  int hash_val = getHash(word);
  wordItem* prev = NULL;
  wordItem* val = hashTable[hash_val];
  while(val != NULL) {
    prev = val;
    val = val->next;
  }
  val = new wordItem;
  val->count = 1;
  val->word = word;
  val ->next = NULL;
  if (prev == NULL) {
    hashTable[hash_val]= val;
  }
  else {
    prev->next = val;
  }
} //Done

int HashTable::getTotalNumberNonStopWords() {
  int count = 0;
  string line;
  for(int i = 0; i < hashTableSize; i++){
    if(hashTable[i] != NULL){
      line = hashTable[i]->word;
      if(!isStopWord(line)){
        count = count + hashTable[i]->count;
      }
    }
  }
  return count;
} //Done

void HashTable::printTopN(int n) {
  vector <wordItem*> TopArr;
  for(int i = 0; i < hashTableSize; i++){
    if(hashTable[i] != NULL && hashTable[i]->count > 150){
      TopArr.push_back(hashTable[i]);
    }
  }
  for(int k = 0; k < 10000; k++){
    for(int j = 0; j < TopArr.size() - 1; j++){
      if(TopArr[j]->count < TopArr[j+1]->count){
        wordItem* temp = TopArr[j];
        TopArr[j] = TopArr[j+1];
        TopArr[j+1] = temp;
      }
    }
  }
  for(int l = 0; l < n; l++){
    cout << TopArr[l]->count << " - " << TopArr[l]->word << endl;
  }
}

int HashTable::getNumUniqueWords() {

}

int HashTable::getNumCollisions() {

}

int HashTable::getHash(string word) { //Private Member function
  int hash = 5381;
  string s(word);
  for(string::iterator i = s.begin(); i != s.end(); i++) {
    hash = hash*33 + (int)*i;
  }
  hash = hash % hashTableSize;
  if(hash < 0) {
    hash += hashTableSize;
  }
  return hash;
} //Done

wordItem* HashTable::searchTable(string word){ //Private Member function

}
