class Solution
{
public:
  bool increasingTriplet(vector<int> &nums)
  {
    int n = nums.size();
    // Trivial Case
    if (n < 3)
      return false;
    int lowest = INT_MAX;
    int mid = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] > mid)
        return true;
      else if (nums[i] > lowest && nums[i] < mid)
        mid = nums[i];
      else if (nums[i] < lowest)
        lowest = nums[i];
    }
    return false;
  }
};