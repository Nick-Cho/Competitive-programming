class Solution
{
public:
  int checkPalindrome(string s, int left, int right)
  {
    if (s == "" || left > right)
    {
      return 0;
    }
    //Runs a loop that starts left and right "pointers" on 2 ends of the substring and checks for the longest                 //palindromic substring
    while (left >= 0 && right < s.length() && s.at(left) == s.at(right))
    {
      left--;
      right++;
    }
    return right - left - 1; //After loop is ran this is how we would get the palindrome's length
  }

  string longestPalindrome(string s)
  {
    if (s == "" || s.length() < 1)
    {
      return "";
    }
    int start = 0;
    int end = 0;

    for (int i = 0; i < s.length(); i++)
    {                                              //i acts as the "middle" of the substring we are trying to if is a                                                        //palindrome or not
      int odd_len = checkPalindrome(s, i, i);      //Case where substring has an odd length
      int even_len = checkPalindrome(s, i, i + 1); //Case where substring has an even length
      int len = max(odd_len, even_len);

      //Setting new substring
      if (len > end - start)
      {
        start = i - ((len - 1) / 2);
        end = i + ((len) / 2);
      }
    }
    return s.substr(start, end - start + 1);
  }
};