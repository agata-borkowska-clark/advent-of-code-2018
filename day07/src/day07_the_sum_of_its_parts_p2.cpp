#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>

int main() {
  std::ifstream in("input");
  std::string entry;

  int NUMBER_OF_WORKERS = 5;

  struct node {
    std::set<char> predecessors;
    std::set<char> successors;
    int time;
    int time_finished;
  };
  std::set<char> ready;
  std::map<char, node> nodes;
  while (std::getline(in, entry)) {
    char name = entry.at(5);
    char successor = entry.at(36);
    if (nodes.find(name) != nodes.end()) {
      nodes[name].successors.insert(successor);
    } else {
      node n;
      n.successors.insert(successor);
      n.time = 60 + name - 'A' + 1;
      nodes.insert(std::pair<char, node>(name, n));
    }
    if (nodes.find(successor) != nodes.end()) {
      nodes[successor].predecessors.insert(name);
    } else {
      node s;
      s.predecessors.insert(name);
      s.time = 60 + successor - 'A' + 1;
      nodes.insert(std::pair<char, node>(successor, s));
    }
  }
  // add all nodes which don't have a predecessor
  for (auto n : nodes) {
    if (n.second.predecessors.empty()) {
      ready.insert(n.first);
    }
  }
  int t = 0;
  char workers[] = {'0', '0', '0', '0', '0'};
  auto it = ready.begin();
  for (int i = 0; i < NUMBER_OF_WORKERS; i++) {
    // if we've got a task available, assign it
    if (!ready.empty()) {
      workers[i] = *ready.begin();
      nodes[*ready.begin()].time_finished = nodes[*ready.begin()].time;
      ready.erase(*ready.begin());
    } else {
      break;
    }
  }

  while (!nodes.empty()) {
    // work out next finish time
    int first_finish_time = -1;
    int first_finished_worker = 0;
    for (int i = 0; i < NUMBER_OF_WORKERS; ++i) {
      if (workers[i] != '0') {
        int workers_finish_time = nodes[workers[i]].time_finished;
        if (first_finish_time == -1 || workers_finish_time < first_finish_time) {
          first_finish_time = workers_finish_time;
          first_finished_worker = i;
        }
      }
    }
    t = first_finish_time; // move to the point in time when the task is finished
    char first_finished_task = workers[first_finished_worker];
    workers[first_finished_worker] = '0'; // free up the worker
    // if more tasks become available, add them to the queue
    // char first_in_queue = *ready.begin();
    for (auto s : nodes[first_finished_task].successors) {
      nodes[s].predecessors.erase(first_finished_task);
      if(nodes[s].predecessors.empty()) {
        ready.insert(s);
      }
    }

    for (int i = 0; i < NUMBER_OF_WORKERS; i++) {
      if (workers[i] == '0') {
        if (!ready.empty()) {
          workers[i] = *ready.begin();
          nodes[*ready.begin()].time_finished = nodes[*ready.begin()].time + t;
          ready.erase(*ready.begin());
        } else {
          break;
        }
      }
    }

    
    nodes.erase(first_finished_task);
  }
  std::cout << t << '\n';
}
