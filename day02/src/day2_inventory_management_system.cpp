#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

int main() {
  std::ifstream in("input");
  int count_2_letters = 0;
  int count_3_letters = 0;
  std::string id;
  while (std::getline(in, id)) {
    std::map<char, int> letter_count;
    for (char& c : id) {
      letter_count[c]++;
    }
    std::set<int> counts;

    std::transform(begin(letter_count), end(letter_count), std::inserter(counts, counts.begin()), 
                [](const std::map<char,int>::value_type &pair) {
        return pair.second;
    });
    if (counts.find(2) != counts.end()) {
      count_2_letters++;
    }
    if (counts.find(3) != counts.end()) {
      count_3_letters++;
    }
  }
  std::cout << count_3_letters*count_2_letters << '\n';
  return 0;
}