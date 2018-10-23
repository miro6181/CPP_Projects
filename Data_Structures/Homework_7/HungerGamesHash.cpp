#include <iostream>
#include "HashTable.hpp"

using namespace std;

HashTable::HashTable(int hashTableSize) {

}

HashTable::~HashTable() {

}

void HashTable::getStopWords(char *ignoreWordFileName) {

}

bool HashTable::isStopWord(string word) {

}

bool HashTable::isInTable(string word) {

}

void HashTable::incrementCount(string word) {

}

void HashTable::addWord(string word) {

}

int HashTable::getTotalNumberNonStopWords() {

}

void HashTable::printTopN(int n) {

}

int HashTable::getNumUniqueWords() {

}

int HashTable::getNumCollisions() {

}

int HashTable::getHash(string word) {
  int hash = 5381;
  string s(word);
  for(auto i = s.begin(); i < s.end(); i++) {
    hash = hash*33 + i;
  }
  hash = hash % hashTableSize
  if(hash < 0) {
    hash += hashTableSize;
  }
  return hash;
}

wordItem* HashTable::searchTable(string word){

}
