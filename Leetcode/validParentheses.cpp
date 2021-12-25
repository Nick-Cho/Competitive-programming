class Solution
{
public:
  bool sameParen(char a, char b)
  {
    if (a == '(' && b == ')')
    {
      return true;
    }
    else if (a == '[' && b == ']')
    {
      return true;
    }
    else if (a == '{' && b == '}')
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool openBracket(char bracket)
  {
    if (bracket == '(' || bracket == '[' || bracket == '{')
    {
      return true;
    }
    return false;
  }

  bool isValid(string s)
  {
    stack<char> stack;
    for (int i = 0; i < s.size(); i++)
    {
      if (openBracket(s[i]))
      {
        stack.push(s[i]);
      }
      else
      {
        if (stack.empty())
        {
          return false;
        }
        if (!sameParen(stack.top(), s[i]))
        {
          return false;
        }
        else
        {
          stack.pop();
        }
      }
    }
    if (stack.empty())
    {
      return true;
    }
    return false;
  }
};