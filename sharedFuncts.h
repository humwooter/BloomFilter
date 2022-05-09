#include <iostream>
#include <vector>
using namespace std;


unsigned int convert_stringToInt(std::string element);
unsigned int strToInt(std::string element);

// unsigned int convert_stringToInt(std::string element) { //converts string like "1001" to an int value 1001                                                                                     
//   if (element.size() > 19) return std::stoll(element.substr(0,19),nullptr, 10);
//   return std::stoll(element,nullptr, 10);
// }
// unsigned int strToInt(std::string element) {                                                                                                                                                  
//   vector<int> char_vals;

//   for (char c : element) {
//     char_vals.push_back(int(c));
//   }

//   string string_to_int = ""; //each character becomes a val in the range 0-9                                                                                                                                

//   for (int x : char_vals) {
//     string_to_int += std::to_string(x%10);
//   }
//   int result = convert_stringToInt(string_to_int)%2147483647; //ensures that int value doesn't exceed size of long int                                                                                      
//   //cout << "string to int val: " << result << endl;///                                                                                                                                                     
//   return result;
// }
// unsigned int BloomFilter::strToInt(std::string element) {                                                                                                                                                

//   vector<int> char_vals;                                                                                                                                                                                 
//   int str_to_int = 0;                                                                                                                                                                                    
//   for (char c : element) char_vals.push_back(int(c));                                                                                                                                                    
//   for (int i = 1; i <= char_vals.size(); i++) str_to_int += (i*(char_vals[i]%10));                                                                                                                       
//   return str_to_int;                                                                                                                                                                                     
// }      
