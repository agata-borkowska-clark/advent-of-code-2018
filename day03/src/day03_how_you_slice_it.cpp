#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

int main() {
  std::ifstream in("input");
  std::string claim;
  std::map<std::string, int> covers;
  while (std::getline(in, claim)) {
    int start_x = std::stoi(claim.substr(claim.find('@') + 2));
    int start_y = std::stoi(claim.substr(claim.find(',') + 1));
    int length_x = std::stoi(claim.substr(claim.find(':') + 2));
    int length_y = std::stoi(claim.substr(claim.find('x') + 1));
    for (int y = 0; y < length_y; y++) {
      for (int x = 0; x < length_x; x++) {
        std::string map_key = "" + std::to_string(start_x + x) + "_" + std::to_string(start_y + y);
        ++covers[map_key];
      }
    }
  }
  const std::size_t overlaps = std::count_if(
    begin(covers), 
    end(covers), 
    [](auto pair) {
      return pair.second > 1;
  });
  std::cout << overlaps << std::endl;
}