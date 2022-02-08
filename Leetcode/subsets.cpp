class Solution
{
public:
  void subsetUtil(vector<int> &nums, vector<vector<int>> &output, vector<int> &v, int index)
  {
    output.push_back(v);
    for (int i = index; i < nums.size(); i++)
    {
      v.push_back(nums[i]);

      subsetUtil(nums, output, v, i + 1);

      v.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> output;
    vector<int> v;
    if (nums.size() < 1)
    {

      return output;
    }
    int index = 0;
    subsetUtil(nums, output, v, index);
    return output;
  }
};