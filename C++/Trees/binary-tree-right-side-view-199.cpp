// Level Order Traversal with a Twist - [Leetcode 199](https://leetcode.com/problems/binary-tree-right-side-view/description/)

#include <vector>
#include <queue>
#include "treeNode.h"

using namespace std;

vector<int> rightSideView(TreeNode *root) {
  vector<int> ans;

  if (!root) {
    return ans;
  }
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();

    for (int i = 0; i < size; i++) {
      TreeNode *temp = q.front();
      q.pop();

      if (i == size - 1) {
        ans.push_back(temp->val);
      }

      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
  return ans;
}