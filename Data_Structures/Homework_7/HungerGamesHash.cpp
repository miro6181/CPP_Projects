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

void HashTable::addWord(string word) {
  int hash_val = getHash(word);
  wordItem* prev = NULL;
  wordItem* entry = hashTable[hash_val];
  while (entry != NULL) {
    prev = entry;
    entry = entry->next;
  }
  if (entry == NULL) {
    entry = new wordItem;
    entry->count = 1;
    entry->word = word;
    entry ->next = NULL;
    if (prev == NULL) {
      hashTable[hash_val]= entry;
    }
    else {
      prev->next = entry;
    }
  }
  incrementCount(word);
  entry->word = word;
} //Done

int HashTable::getTotalNumberNonStopWords() {

}

void HashTable::printTopN(int n) {
  vector<wordItem*> TopN;
  wordItem* temp;
  for (int i = 0; i < hashTableSize; i++) {
    temp = hashTable[i];
    while (temp != NULL) {
      for (int j = 0; j < n; j++) {
        if(arr[j]->count <= temp->count && arr[j+1]->count <= temp->count) {
          for (int k = 0; k < j; k++) {
            arr[k] = arr[k+1]
          }
          arr[j]=arr[j+1];
          arr[j] = temp;
        }
      }
      temp = temp->next;
    }
  }
  for (int k = 0; k < n; k++) {
    std::cout << arr[k]->word << "--" << arr[k]->count;
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
