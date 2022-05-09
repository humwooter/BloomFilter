#include "HashTable.h"
#include "sharedFuncts.h"

HashTable::HashTable(int q) {
  tableSize = q;
  table = new LinkedList[tableSize]();
}; //seperate chaining hashtable. q is the size of the hash table (prime #). Will be used for removed elements in bloomfilter/  
void HashTable::insert(std::string element){
  int index = strToInt(element) % tableSize;
  table[index].insert_node(element);
}
void HashTable::remove(std::string element){
  int index = strToInt(element) % tableSize;
  table[index].remove_node(element);
}
bool HashTable::find(std::string element){
  int index = strToInt(element) % tableSize;
  return table[index].find_node(element);
}
