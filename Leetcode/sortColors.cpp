class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int i, key, j;
    int n = nums.size();
    for (i = 0; i < n; i++)
    {
      key = nums[i];
      j = i - 1;
      while (j >= 0 && nums[j] > key)
      {
        nums[j + 1] = nums[j];
        j--;
      }
      nums[j + 1] = key;
    }
  }
};