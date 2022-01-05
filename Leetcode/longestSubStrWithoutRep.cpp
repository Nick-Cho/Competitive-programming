class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    string subStr = "";
    string bestStr = "";

    for (int i = 0; i < s.size(); i++)
    {
      if (subStr.find(s[i]) == string::npos)
      { //Case where char is not in substring
        subStr.push_back(s[i]);
        if (subStr.size() > bestStr.size())
        {
          bestStr = subStr; //Setting new longest substring
        }
      }
      else
      {
        subStr.erase(0, subStr.find(s[i]) + 1); //Resetting substring var if repeated character is found
        subStr.push_back(s[i]);
      }
    }
    return bestStr.size();
  }
};