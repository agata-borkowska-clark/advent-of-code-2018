#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>

int main() {
  std::ifstream in("input");
  std::string entry;

  struct node {
    std::set<char> predecessors;
    std::set<char> successors;
  };
  std::set<char> ready;
  std::map<char, node> nodes;
  while (std::getline(in, entry)) {
    char name = entry.at(5);
    char successor = entry.at(36);
    if (nodes.find(name) != nodes.end()) {
      nodes.find(name)->second.successors.insert(successor);
    } else {
      node n;
      n.successors.insert(successor);
      nodes.insert(std::pair<char, node>(name, n));
    }
    if (nodes.find(successor) != nodes.end()) {
      nodes.find(successor)->second.predecessors.insert(name);
    } else {
      node s;
      s.predecessors.insert(name);
      nodes.insert(std::pair<char, node>(successor, s));
    }
  }
  // add all nodes which don't have a predecessor
  for (auto n : nodes) {
    if (n.second.predecessors.empty()) {
      ready.insert(n.first);
    }
  }
  while (!ready.empty()) {
    char first_in_queue = *ready.begin();
    std::cout << first_in_queue;
    ready.erase(first_in_queue);
    std::pair<char, node> first_node = *nodes.find(first_in_queue);
    for (auto s : first_node.second.successors) {
      (*nodes.find(s)).second.predecessors.erase(first_in_queue);
      if((*nodes.find(s)).second.predecessors.empty()) {
        ready.insert((*nodes.find(s)).first);
      }
    }
  }
  std::cout << '\n';
}
