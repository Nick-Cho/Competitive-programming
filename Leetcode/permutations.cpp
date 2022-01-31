class Solution
{
public:
  void solve(vector<int> &num, int idx, vector<vector<int>> &ans)
  {
    // Base case
    if (idx >= num.size())
    {
      ans.push_back(num);
      return;
    }

    for (int j = idx; j < num.size(); j++)
    {
      // Ek case solve karo ...
      swap(num[idx], num[j]);
      // Baki recursion sambhal lega ...
      solve(num, idx + 1, ans);
      // Backtracing...
      swap(num[idx], num[j]);
    }
  }
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
  }
};