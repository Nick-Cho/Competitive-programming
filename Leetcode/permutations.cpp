class Solution
{
public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<int> next = nums;
    vector<vector<int>> ans;
    ans.push_back(nums);
    while (prev_permutation(nums.begin(), nums.end()))
      ans.push_back(nums);
    while (next_permutation(next.begin(), next.end()))
      ans.push_back(next);
    return ans;
  }
};