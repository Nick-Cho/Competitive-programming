class Solution
{
public:
  string sortString(string s)
  {
    sort(s.begin(), s.end());

    return s;
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<vector<string>> answer;
    if (strs.size() <= 1)
    {
      answer.push_back(strs);
      return answer;
    }
    unordered_map<string, int> m;
    int idx = 0;
    for (int i = 0; i < strs.size(); i++)
    {
      string str = sortString(strs[i]);
      if (m.find(str) != m.end())
      {
        answer[m[str]].push_back(strs[i]);
      }
      else
      {
        m[str] = idx;
        idx++;
        vector<string> arr;
        arr.push_back(strs[i]);
        answer.push_back(arr);
      }
    }
    return answer;
  }
};