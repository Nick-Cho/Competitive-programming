class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    // O(n) solution
    vector<int> output;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
      int n = target - nums[i];
      if (m.find(n) != m.end())
      {

        output.push_back(i);
        output.push_back(m[n]);
        return output;
      }
      m[nums[i]] = i;
    }
    return output;

    //         O(n^2) solution
    //         vector<int> output;
    //         for (int i = 0; i<nums.size(); i++){
    //             for (int j = 0; j<nums.size(); j++){
    //                 if (nums[i] + nums[j] == target && i != j){
    //                     output.push_back(i);
    //                     output.push_back(j);
    //                     return output;
    //                 }
    //             }
    //         }
    //         return output;
  }
};