#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream in("input");
  int current_frequency = 0;
  std::string change;
  while (std::getline(in, change)) {
    int change_as_int = std::stoi(change);
    current_frequency += change_as_int;
  }
  std::cout << current_frequency << '\n';
  return 0;
}