#include "BloomFilter.h"
#include <iostream>
#include <fstream>

vector<string> fileToVector(string filename){
  ifstream file;
  vector<string> words;

  file.open(filename);

  if(!file.is_open()){
    cout << "error opening file"<< filename << endl; 
    return words;
  }
  string input;
  while(getline(file,input)){
    words.push_back(input);
  }
  file.close();

  return words;
}

void phases(int phaseNum, BloomFilter a, vector<string>& input, vector<string>& successfulSearch, vector<string>& failedSearch, vector<string>& remove, vector<int>& false_NegPos, vector<string>& falsePos_elems, vector<int>& total_false_NegPos) {
  falsePos_elems.clear();
  false_NegPos[0] = 0;
  false_NegPos[1] = 0;
  
  for (int i = (phaseNum-1)*1000; i < 1000*phaseNum; i++) a.insert(input[i]); //inserting first 1000 words in input.txt into bloomfilter
  cout << "Phase " << phaseNum << ":" << endl;
  for (int i = (phaseNum-1)*100; i < 100*phaseNum; i++) {
    if (a.find(successfulSearch[i]) == false) false_NegPos[0] += 1;
    if (a.find(failedSearch[i]) == true) {
      falsePos_elems.push_back(failedSearch[i]);
      false_NegPos[1] += 1;
    }
  }
  total_false_NegPos[0] += false_NegPos[0];
  total_false_NegPos[1] += false_NegPos[1];
  for (int i = (phaseNum-1)*100; i < 100*phaseNum; i++) a.remove(remove[i]);       

  cout << "Number of false negatives:\n" << false_NegPos[0] << endl;
  cout << "Number of false positives:\n" << false_NegPos[1] << endl;
  cout << "Probability of false positives:" << (false_NegPos[1]*1.0)/100. << endl;

  cout << "False Positive Elements:\n";
  for (std::string s : falsePos_elems) cout << s << endl; 
}

int main(int argc, char *argv[]) {

  vector<string> setup = fileToVector(argv[1]);
  vector<int> false_NegPos = {0,0}; //index 0 stores false negatives and index 1 stores false positives
  vector<int> total_false_NegPos = {0,0};
  vector<string> falsePos_elems;    
  vector<string> input = fileToVector(argv[2]);
  vector<string> successfulSearch = fileToVector(argv[3]);
  vector<string> failedSearch = fileToVector(argv[4]);
  vector<string> remove = fileToVector(argv[5]);

  ofstream outfile;
  outfile.open("output.txt");
    
  for (int i = 0; i < 10; i++) { //running 10 trials of 10 phases each to calculate statistics:
    BloomFilter test(stod(setup[i*4]),stod(setup[i*4 +1]), stod(setup[i*4 + 2]), stod(setup[i*4 +3]));
    cout << "Experiment for values of: " << endl;
    cout << "p = " << setup[i*4] << endl;
    cout << "c = " << setup[i*4 + 2] << endl;
    cout << "d = " << setup[i*4 +3] << endl;
    cout << "q = " << test.getHashTableSize() << endl;
    //cout << "number of hash functions " << test.getNumHashFunctions() << endl; 
    for (int j = 1; j <= 10; j++)
      {
        phases(j, test, input, successfulSearch, failedSearch, remove, false_NegPos, falsePos_elems, total_false_NegPos);
      }
    
    //save stats to out.txt
    outfile << total_false_NegPos[0] << endl;
    outfile << total_false_NegPos[1] << endl;
    outfile << (total_false_NegPos[1]*1.0)/1000. << endl << endl;

    cout <<  "After all phases: " << endl;
    cout << "Number of false negatives:" << endl;
    cout << total_false_NegPos[0] << endl;
    cout << "Number of false positives:" << endl;
    cout << total_false_NegPos[1] << endl;
    cout << "Probability of false positives:" << endl;
    cout << (total_false_NegPos[1]*1.0)/1000. << endl;

    total_false_NegPos[0] = 0; //resetting total false negatives/positives                                                                                                                              
    total_false_NegPos[1] = 0; //resetting total false negatives/positives         
  }
  outfile.close();

  return 0;
}
