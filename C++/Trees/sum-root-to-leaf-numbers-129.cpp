// Basic Path DFS - [Leetcode 129](https://leetcode.com/problems/sum-root-to-leaf-numbers/)

#include <string>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

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