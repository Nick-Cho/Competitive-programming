class Solution
{
public:
  bool checkIfPangram(string sentence)
  {
    unordered_map<char, int> m;
    int n = sentence.length();
    for (int i = 0; i < n; i++)
    {
      if (m.find(sentence[i]) == m.end())
      {
        m[sentence[i]] = 1;
      }
    }
    if (m.size() == 26)
      return true;
    return false;
  }
};