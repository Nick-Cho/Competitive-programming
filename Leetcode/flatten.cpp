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
  TreeNode *flat(TreeNode *root)
  {
    if (!root)
      return NULL;
    TreeNode *l = flat(root->left);
    TreeNode *r = flat(root->right);
    if (!l)
      root->right = r;
    else
    {
      root->right = l;
      while (l->right)
        l = l->right;
      l->right = r;

      l->left = NULL;
      root->left = NULL;

      if (r)
        r->left = NULL;
    }

    return root;
  }

  void flatten(TreeNode *root)
  {
    root = flat(root);
  }
};