#include <iostream>
#include <tuple>
#include <algorithm>

int serial_number = 18;
int grid[300][300];

int calculate_cell(int x, int y) {
  int rack_id = x + 10;
  int result = (rack_id * y + serial_number);
  result *= rack_id;
  result = (result / 100) % 10;
  return result - 5;
}

int calculate_square_value(int x, int y, int dimension) {
  int result = 0;
  for (int i = 0; i < dimension; ++i) {
    for (int j = 0; j < dimension; ++j) {
      result += grid[x - i][y - j];
    }
  }
  return result;
}

int main() {
  int max_square_value = 0; // I know, assumption
  std::tuple<int, int, int> max_square_coordinates;
  max_square_coordinates = std::make_tuple(0, 0, 0);
  for (int x = 0; x < 300; ++x) {
    for (int y = 0; y < 300; ++y) {
      // calculate this field
      grid[x][y] = calculate_cell(x, y);

      // if this is a valid bottom-right corner of a 3x3 square, calculate that square and check against max
      for (int i = 0; i < std::min(x, y); ++i) {
        int this_square = calculate_square_value(x, y, i);
        if (this_square > max_square_value) {
          max_square_value = this_square;
          max_square_coordinates = std::make_tuple(x - i + 1, y - i + 1, i);
        }
      }
    }
  }
  std::cout << std::get<0>(max_square_coordinates) << ',' << std::get<1>(max_square_coordinates) << ',' << std::get<2>(max_square_coordinates) << '\n';
}
