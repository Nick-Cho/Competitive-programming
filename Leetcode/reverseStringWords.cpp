class Solution
{
public:
  void simple_tokenizer(string s, stack<string> &st)
  {
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
      st.push(word);
    }
  }
  string reverseWords(string s)
  {
    stack<string> st;
    string output;
    simple_tokenizer(s, st);
    output = st.top();
    st.pop();
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
      output = output + " " + st.top();
      st.pop();
    }
    return output;
  }
};