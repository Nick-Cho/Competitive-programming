class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    //    O(b) solution
    int best_sum = -10000;
    int max_sub_array = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      max_sub_array += nums[i];
      if (max_sub_array > best_sum)
      {
        best_sum = max_sub_array;
      }
      if (max_sub_array < 0)
      {
        max_sub_array = 0;
      }

      // best_sum = std::max(nums[i], nums[i] + best_sum);
    }

    return best_sum;
    //  O(n^2) solution
    //         int best_sum = nums[0];
    //         vector<int> best_sub_array;

    //         for (int i = 0; i < nums.size(); i++){
    //             int curr_sum = 0;
    //             for (int j = i; j < nums.size(); j++){
    //                 curr_sum += nums[j];
    //                 if(curr_sum > best_sum){
    //                     best_sum = curr_sum;
    //                 }
    //             }
    //         }
    //         return best_sum;
  }
};