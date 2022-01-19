class Solution
{
public:
  vector<string> map = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  vector<string> getKPC(string str)
  {
    if (str.length() == 0)
    {
      vector<string> base;
      string element;
      element = "";
      base.push_back(element);
      return base;
    }

    char prev = (str[0]);
    string next = str.substr(1, str.length() - 1);

    vector<string> res = getKPC(next);
    vector<string> ans;

    for (int index = 0; index < map[prev - '0'].length(); index++)
    {
      for (int j = 0; j < res.size(); j++)
        ans.push_back(map[prev - '0'][index] + res[j]);
    }

    return ans;
  }

  vector<string> letterCombinations(string str)
  {
    if (str.size() == 0)
      return {};
    return getKPC(str);
    -
  }
};