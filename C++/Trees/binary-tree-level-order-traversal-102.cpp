// BFS on Binary Tree - [Leetcode 102](https://leetcode.com/problems/binary-tree-level-order-traversal/description)

#include <queue>
#include <vector>
#include "treeNode.h"

using namespace std;


vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;

    if (!root)
    {
        return ans;
    }
    // Basic Breath First Search
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            // Look at each node in the queue
            TreeNode *temp = q.front();
            q.pop();
            level.push_back(temp->val);

            // Add children nodes if they exist
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        // Add level to the Ans
        ans.push_back(level);
    }

    return ans;
}
