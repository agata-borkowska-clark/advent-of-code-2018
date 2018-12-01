#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream in("input");

  int current_frequency = 0;
	std::string change;
	while (std::getline(in, change)) {
    std::string abs_value_as_string = change.substr(1);
    int abs_value_as_int = std::stoi(abs_value_as_string);
    if (change.at(0) == '+') {
      current_frequency += abs_value_as_int;
    } else {
      current_frequency -= abs_value_as_int;
    }
	}
   std::cout << current_frequency << '\n';
   return 0;
 }