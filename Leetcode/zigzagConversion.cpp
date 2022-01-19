class Solution
{
public:
  string convert(string s, int numRows)
  {
    if (numRows == 1)
      return s; //Base case
    int n = s.size();
    string ans[numRows]; //Creating an array of strings for each row
    string output;
    //initializing var's to keep track of where we are in the zig zag
    int row = 0;
    bool down = true; //True if we are moving down in the zigzag pattern and false if we are moving up the zigzag                               //pattern

    for (int i = 0; i < n; i++)
    {
      ans[row].push_back(s[i]); //adding current character to respective row in zigzag

      //updating down boolean based on row position
      if (row == numRows - 1)
        down = false;
      else if (row == 0)
        down = true;

      //updating next row position based on down boolean
      (down) ? (row++) : (row--);
    }

    for (int i = 0; i < numRows; i++)
    {
      output += ans[i];
    }
    return output;
  }
};