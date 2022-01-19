class Solution
{
public:
  void createCombs(int n, int open, int closed, string s, vector<string> &ans)
  {
    //when both open and closed reach n we have a valid parentheses so we add the string to the answer vector
    if (open == n && closed == n)
    {
      ans.push_back(s);
      return;
    }
    if (open < n)
    {
      createCombs(n, open + 1, closed, s + "(", ans);
    }
    if (closed < open)
    {
      createCombs(n, open, closed + 1, s + ")", ans);
    }
  }

  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    int open = 0;   //keeps track of how many open brackets there are
    int closed = 0; //keeps track of how many closed brackets there are
    createCombs(n, open, closed, "", ans);
    return ans;
  }
};