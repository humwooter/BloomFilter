#include "sharedFuncts.h"
#include <cmath>
#include <stdlib.h>
#include <bits/stdc++.h>


unsigned int strToInt(std::string element) {
  unsigned int finalInt = 0;

  for (char c : element) {
    srand(int(c));
    int multiplier = rand();
    long long int val = int(c)*multiplier;
    finalInt += val%2147483647;
  }
  return finalInt;
}

