#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

int main() {
  std::ifstream in("input");
  std::vector<std::string> ids;
  std::string id;
  while (std::getline(in, id)) {
    for (auto candidate : ids) {
      bool match = true;
      int first_strike = -1;
      for (int i = 0; i < candidate.length(); i++) {
        if (candidate[i] != id[i]) {
          if (first_strike > -1) {
            match = false;
            break;
          } else {
            first_strike = i;
          }

        }
      }
      if (match) {
        for (int j = 0; j < id.length(); j++) {
          if (j == first_strike) {
            continue;
          } else {
            std::cout << id.at(j);
          }
        }
        std::cout << '\n';
        return 0;
      }
    }
    ids.push_back(id);
  }
  return 1;
}