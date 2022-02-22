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
  int findPos(vector<int> inorder, int element, int n)
  {
    for (int i = 0; i < n; i++)
    {
      if (inorder[i] == element)
        return i;
    }
    return -1;
  }

  TreeNode *solve(vector<int> preorder, vector<int> inorder, int &prestart, int instart, int inend, int n)
  {
    if (prestart >= n || instart > inend)
    {
      return NULL;
    }

    int ele = preorder[prestart++];     // starting ele of preorder
    TreeNode *root = new TreeNode(ele); // creating new node

    // now finding ele position in inorder
    int pos = findPos(inorder, ele, n);

    // recursive call
    root->left = solve(preorder, inorder, prestart, instart, pos - 1, n);
    root->right = solve(preorder, inorder, prestart, pos + 1, inend, n);

    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    int n = inorder.size();
    int preInd = 0;
    TreeNode *ans = solve(preorder, inorder, preInd, 0, n - 1, n); // 0 = start of inorder , n-1 = end of in
    return ans;
  }
};