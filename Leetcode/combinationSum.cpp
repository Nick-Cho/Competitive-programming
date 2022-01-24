class Solution
{
public:
  void findNumbers(vector<int> &candidates, int target, vector<vector<int>> &ret, vector<int> &r, int i)
  {
    if (target == 0)
    {
      ret.push_back(r);
      return;
    }

    while (i < candidates.size() && ((target - candidates[i]) >= 0))
    {
      r.push_back(candidates[i]);

      findNumbers(candidates, target - candidates[i], ret, r, i);
      i++;

      r.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    vector<int> r;
    vector<vector<int>> ret;
    findNumbers(candidates, target, ret, r, 0);
    return ret;
  }
};