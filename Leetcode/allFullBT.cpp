class Solution
{
public:
  map<int, vector<TreeNode *>> mem;
  vector<TreeNode *> util(int n)
  {
    if (n == 1)
      return {new TreeNode(0)};
    if (mem.find(n) != mem.end())
      return mem[n];
    n--;
    vector<TreeNode *> res;
    for (int i = 1; i < n; i += 2)
    {
      vector<TreeNode *> left = util(i);
      vector<TreeNode *> right = util(n - i);
      for (TreeNode *j : left)
      {
        for (TreeNode *k : right)
        {
          TreeNode *root = new TreeNode(0);
          root->left = j;
          root->right = k;
          res.push_back(root);
        }
      }
    }
    return mem[n] = res;
  }
  vector<TreeNode *> allPossibleFBT(int n)
  {
    if (n % 2 == 0)
      return {};
    return util(n);
  }
};