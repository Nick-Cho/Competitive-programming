class Solution
{
public:
  bool checkExist(vector<vector<char>> &board, string word, int x, int y, int nrow, int mcol, int level)
  {
    int l = word.length();
    // word matched
    if (level == l)
      return true;
    // out of boundary
    if (x < 0 || y < 0 || x >= nrow || y >= mcol)
      return false;

    if (board[x][y] == word[level])
    {
      // marking cell as visited
      char temp = board[x][y];
      board[x][y] = '#';

      bool res = checkExist(board, word, x + 1, y, nrow, mcol, level + 1) ||
                 checkExist(board, word, x - 1, y, nrow, mcol, level + 1) ||
                 checkExist(board, word, x, y + 1, nrow, mcol, level + 1) ||
                 checkExist(board, word, x, y - 1, nrow, mcol, level + 1);

      board[x][y] = temp; // unmarking cell
      return res;
    }
    else
    {
      return false;
    }
  }

  bool exist(vector<vector<char>> &board, string word)
  {
    int n = board.size();
    int m = board[0].size();
    if (word.length() > (n * m))
    {
      return false;
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (board[i][j] == word[0])
        {
          if (checkExist(board, word, i, j, n, m, 0))
          {
            return true;
          }
        }
      }
    }
    return false;
  }
};