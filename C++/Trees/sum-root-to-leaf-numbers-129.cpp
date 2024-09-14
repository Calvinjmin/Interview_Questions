// Basic Path DFS - [Leetcode 129](https://leetcode.com/problems/sum-root-to-leaf-numbers/)

#include <string>
#include "treeNode.h"

using namespace std;


int dfs(TreeNode *n, string path) {
  if (!n) {
    return 0;
  }
  path = path + to_string(n->val);
  if (!n->left && !n->right) {
    return stoi(path);
  }
  return dfs(n->left, path) + dfs(n->right, path);
}

int sumNumbers(TreeNode *root) { return dfs(root, ""); }