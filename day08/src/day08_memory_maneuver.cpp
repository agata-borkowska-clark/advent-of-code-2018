#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <numeric>

struct node {
  int child_count;
  int meta_count;
  int parent;
  int value;
  std::vector<int> children;
  std::vector<int> metadata;
};

std::vector<node> tree;
std::vector<int> raw_input;

int meta_sum = 0;

int process_node(int parent, int index) {
  node n;
  n.parent = parent;
  n.child_count = raw_input[index];
  n.meta_count = raw_input[index + 1];
  n.value = 0;
  if (n.meta_count == 0) {
    return raw_input.size();
  }
  tree.push_back(n);
  int child_start_index = index + 2;
  int node_id = tree.size() - 1;
  // std::cout << "node_id " << node_id << " child start index " << child_start_index << " child count " << n.child_count << '\n';
  if (n.parent != -1) {
    tree[n.parent].children.push_back(node_id);
  }
  for (int i = 0; i < n.child_count; ++i) {
    // std::cout << "processing " << node_id << " child# " << i << '\n';
    child_start_index = process_node(node_id, child_start_index);
  }
  for (int i = 0; i < n.meta_count; ++i) {
    // std::cout << "inserting " << raw_input[child_start_index + i] << " into meta of " << node_id << '\n'; 
    tree[node_id].metadata.push_back(raw_input[child_start_index + i]);
    meta_sum += raw_input[child_start_index + i];
  }

  if (tree[node_id].child_count == 0) {
    tree[node_id].value = std::accumulate(tree[node_id].metadata.begin(), tree[node_id].metadata.end(), 0);
  } else {
    for (auto meta : tree[node_id].metadata) {
      if (meta < tree[node_id].child_count + 1) {
        tree[node_id].value += tree[tree[node_id].children[meta - 1]].value;
      }
    }
  }
  // std::cout << "node_id " << node_id << " with child count " << n.child_count << " and meta count " << n.meta_count << ", meta: ";
  /*for (auto meta : tree[node_id].metadata) {
    std::cout << meta << ", ";
  }
  std::cout << '\n';*/
  return child_start_index + n.meta_count;

}

int main() {
  std::ifstream in("input");
  int i;
  while (in >> i) {
    raw_input.push_back(i);
  }
  process_node(-1, 0);
  std::cout << "part 1: " << meta_sum << '\n';
  std::cout << "part 2: " << tree[0].value << '\n';
}
