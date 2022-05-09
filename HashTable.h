#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

class HashTable{
public: 
  int tableSize; 
  LinkedList *table;
  HashTable(int q); //seperate chaining hashtable. q is the size of the hash table (prime #). Will be used for removed elements in bloomfilter/  
  void insert(std::string element);
  void remove(std::string element);
  bool find(std::string element);
};


