#include <iostream>
#include <fstream>
#include <stack>

int main() {
  std::ifstream in("input");
  char c;
  int min = 10000;
  for (char p = 'A'; p <= 'Z'; ++p) {
    std::stack<char> stack;
    in.clear();
    in.seekg(0, std::ios::beg);
    while (in.get(c)) {
      if (c == p || c == p + 32) {
        continue;
      }
      if (!stack.empty() && (stack.top() == c - 32 || stack.top() == c + 32)) {
        stack.pop();
      } else {
        stack.push(c);
      }
    }
    if (stack.size() < min) {
      min = stack.size();
    }
  }
  std::cout << min << '\n';
  return 0;
}