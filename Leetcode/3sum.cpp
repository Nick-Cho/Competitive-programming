class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> output;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < (int)nums.size() - 2; i++)
    {
      if (i == 0 || (nums[i] != nums[i - 1]))
      {
        int j = i + 1;           //left pointer
        int k = nums.size() - 1; //right pointer

        while (j < k)
        {
          int sum = nums[i] + nums[j] + nums[k];
          if (sum == 0)
          {
            output.push_back({nums[i], nums[j], nums[k]});
            while (j < k && nums[j] == nums[j + 1])
              j++; //for removing the duplicate 'nums[j]'
            while (j < k && nums[k] == nums[k - 1])
              k--; //for removing duplicate 'nums[k]'
            j++;
            k--; //shifting to new value after duplicates are removed
          }
          else if (sum < 0)
          {
            j++; //Moving left pointer up because we need a bigger sum if sum is <0
          }
          else
          {
            k--; //Moving right pointer down because we need a smaller sum if sum is >0
          }
        }
      }
    }
    return output;
  }
};