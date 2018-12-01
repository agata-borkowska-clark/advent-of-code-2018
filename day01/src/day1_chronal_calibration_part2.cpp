#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
  std::ifstream input("input");

  std::map<int, bool> frequencies_seen;
  int current_frequency = 0;
  std::string change;
  while (true) {
    input.clear();
    input.seekg(0, std::ios::beg);
    while (std::getline(input, change)) {
      int change_as_int = std::stoi(change);
      current_frequency += change_as_int;

      if (frequencies_seen[current_frequency] == 1) {
          std::cout << current_frequency << '\n';
          return 0; 
      } else {
        frequencies_seen[current_frequency] = true;
      }
    }
  }
}