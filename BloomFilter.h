#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include "HashTable.h"
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string>


//main API of bloom filter:
//p = prob of false positive
//c = scale factor of bloom filter size
//d = scale factor of num of hash functions
class BloomFilter {

private:
  int n; //bloom filter size
  int k; //num hash functions
  bool *bloom_filter;
public:
  HashTable hashtable;
  BloomFilter(double p, int m, float c, float d);

  void remove(std::string element);
  void insert(std::string element);
  bool find(std::string element);
  int getHashTableSize();
  int getNumHashFunctions() {return k;}
  int getBloomFilterSize() {return n; }

  int bloomFilterSize(double p, int m, float c) const;
  int numHashFunctions(int n, int m, float d) const;
  int hash(unsigned int element, int index);
  long int h(int key, int p, int m, int seed);
  void print(); // for testing
  vector<int> generateCode(int stringToIntVal); //codeForThisWord returns a vector of all the indices in the bloomFilter where the given key would be set to true
  void reset(); //resets the bloomfilter  
  int SieveOfEratosthenes(int n) const;
};
