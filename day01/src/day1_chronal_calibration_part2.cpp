#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
  ifstream input("input");

  std::map<int, bool> frequencies_seen;
  int current_frequency = 0;
  std::string change;
  while (true) {
    input.clear();
    input.seekg(0, ios::beg);
    while (std::getline(input, change)) {
      std::string abs_value_as_string = change.substr(1);
      int abs_value_as_int = std::stoi(abs_value_as_string);
      
      if (change.at(0) == '+') {
        current_frequency += abs_value_as_int;
      } else {
        current_frequency -= abs_value_as_int;
      }

      if (frequencies_seen[current_frequency] == 1) {
          std::cout << current_frequency << '\n';
          return 0; 
      } else {
        frequencies_seen[current_frequency] = true;
      }
    }
  }
}