class Solution
{
public:
  bool isOperator(char input)
  {
    return (input == '-' || input == '+' || input == '*');
  }

  vector<int> possibleResultUtil(string input, map<string, vector<int>> memo)
  {
    if (memo.find(input) != memo.end())
      return memo[input];
    vector<int> res;
    for (int i = 0; i < input.size(); i++)
    {
      if (isOperator(input[i]))
      {
        vector<int> resPre = possibleResultUtil(input.substr(0, i), memo);
        vector<int> resSuf = possibleResultUtil(input.substr(i + 1), memo);

        for (int j = 0; j < resPre.size(); j++)
        {
          for (int k = 0; k < resSuf.size(); k++)
          {
            if (input[i] == '+')
              res.push_back(resPre[j] + resSuf[k]);
            else if (input[i] == '-')
              res.push_back(resPre[j] - resSuf[k]);
            else if (input[i] == '*')
              res.push_back(resPre[j] * resSuf[k]);
          }
        }
      }
    }
    if (res.size() == 0)
      res.push_back(atoi(input.c_str()));

    // Store in memo so that input string is not
    // processed repeatedly
    memo[input] = res;
    return res;
  }

  vector<int> diffWaysToCompute(string expression)
  {
    map<string, vector<int>> memo;
    return possibleResultUtil(expression, memo);
  }
};