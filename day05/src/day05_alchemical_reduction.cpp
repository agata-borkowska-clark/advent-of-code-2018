#include <iostream>
#include <fstream>
#include <stack>

int main() {
  std::ifstream in("input");
  char c;
  std::stack<char> stack;
  while (in.get(c)) {
    if (!stack.empty() && (stack.top() == c - 32 || stack.top() == c + 32)) {
      stack.pop();
    } else {
      stack.push(c);
    }
  }
  std::cout << stack.size() << '\n';
}