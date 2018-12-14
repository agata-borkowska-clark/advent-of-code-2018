#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>

int max_x = 0;
int max_y = 0;
std::vector<std::tuple<int, int, int>> coordinates;

int main() {
  std::ifstream in("input");
  std::string entry;

  // read in the input, record as tuples of <x, y, nearest area count>
  while (std::getline(in, entry)) {
    std::tuple<int, int, int> coord;
    coordinates.push_back(std::make_tuple(std::stoi(entry), std::stoi(entry.substr(entry.find(',') + 1)), 1));
  }
  // find size of the grid
  for (auto coord : coordinates) {
    if (std::get<0>(coord) > max_x) {
      max_x = std::get<0>(coord);
    }
    if (std::get<1>(coord) > max_y) {
      max_y = std::get<1>(coord);
    }
  }

  // lay out the points
  std::pair<int, int> grid[max_x + 1][max_y + 1];
  for (int i = 0; i < coordinates.size(); ++i) {
    std::tuple<int, int, int> coord = coordinates[i];
    std::pair<int, int> point;
    point.first = i;
    point.second = 0;
    grid[std::get<0>(coord)][std::get<1>(coord)] = point;
  }


}
