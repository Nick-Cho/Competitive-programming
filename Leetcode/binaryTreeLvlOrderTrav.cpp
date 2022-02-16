/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> output;
    if (!root)
    {
      return output;
    }
    vector<int> v;
    v.push_back(root->val);
    output.push_back(v);
    // base case
    if (root->left == nullptr && root->right == nullptr)
    {
      return output;
    }

    vector<TreeNode *> parents;
    parents.push_back(root);
    traverse(output, parents);
    return output;
  }

  void traverse(vector<vector<int>> &output, vector<TreeNode *> &parents)
  {
    while (!parents.empty())
    {
      vector<TreeNode *> p;
      vector<int> v;
      for (TreeNode *n : parents)
      {
        if (n->left)
        {
          v.push_back(n->left->val);
          p.push_back(n->left);
        }
        if (n->right)
        {
          v.push_back(n->right->val);
          p.push_back(n->right);
        }
      }
      if (!v.empty())
      {
        output.push_back(v);
      }
      parents = p;
    }
  }
};