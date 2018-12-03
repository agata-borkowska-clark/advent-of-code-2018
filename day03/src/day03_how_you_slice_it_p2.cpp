#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <set>

int main() {
  std::ifstream in("input");
  std::string claim;
  std::map<std::string, int> covers;
  std::set<int> candidates;
  while (std::getline(in, claim)) {
    int id = std::stoi(claim.substr(1));
    int start_x = std::stoi(claim.substr(claim.find('@') + 2));
    int start_y = std::stoi(claim.substr(claim.find(',') + 1));
    int length_x = std::stoi(claim.substr(claim.find(':') + 2));
    int length_y = std::stoi(claim.substr(claim.find('x') + 1));

    int candidate_to_remove = 0;
    for (int y = 0; y < length_y; y++) {
      for (int x = 0; x < length_x; x++) {
        std::string map_key = "" + std::to_string(start_x + x) + "_" + std::to_string(start_y + y);
        if (covers[map_key]) {
          candidate_to_remove = covers[map_key];
          auto it = candidates.find(covers[map_key]);
          if (it != candidates.end()) {
            candidates.erase(it);
          }
        }
        covers[map_key] = id;
      }
    }
    if (!candidate_to_remove) {
      candidates.insert(id);
    }
  }

  std::cout << *candidates.begin() << std::endl;
}