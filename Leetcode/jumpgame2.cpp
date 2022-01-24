class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int *jumps = new int[nums.size()];
    int min = 0;
    jumps[nums.size() - 1] = 0;

    for (int i = nums.size() - 2; i >= 0; i--)
    {
      if (nums[i] == 0)
      {
        jumps[i] = 10000;
      }

      else if (nums[i] >= nums.size() - i - 1)
      {
        jumps[i] = 1;
      }

      else
      {
        min = 10000;

        for (int j = i + 1; j < nums.size() && j <= nums[i] + i; j++)
        {
          if (min > jumps[j])
          {
            min = jumps[j];
          }
        }
        if (min != 10000)
        {
          jumps[i] = min + 1;
        }
        else
          jumps[i] = min;
      }
    }
    return jumps[0];
  }
};