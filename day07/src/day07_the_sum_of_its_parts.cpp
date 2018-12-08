#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>

int main() {
  std::ifstream in("input");
  std::string entry;

  struct node {
    char name;
    std::set<char> predecessors;
    std::set<char> successors;
    bool operator < (const node &second) const { 
      return name < second.name; 
    }
    bool operator == (const node &second) const {
      return name == second.name;
    }
  };
  std::set<node> ready;
  std::set<node> nodes;
  while (std::getline(in, entry)) {
    char name = entry.at(5);
    char successor = entry.at(36);
    node n;
    n.name = name;
    if (nodes.find(n) != nodes.end()) {
      (*nodes.find(n)).successors.insert(successor);
    } else {
      n.successors.insert(successor);
      nodes.insert(n);
    }
    node s;
    s.name = successor;
    if (nodes.find(s) != nodes.end()) {
      (*nodes.find(s)).predecessors.insert(name);
    }
  }
}
