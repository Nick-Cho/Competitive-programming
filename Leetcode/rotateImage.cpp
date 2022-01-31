class Solution
{
public:
  //Swaps values of the array
  void int_swap(vector<vector<int>> &matrix, int &a, int &b)
  {
    int temp = a;
    a = b;
    b = temp;
  }

  void rotate(vector<vector<int>> &matrix)
  {
    //Swapping Arrays
    //Left Right Pointers
    int l_idx = 0;
    int r_idx = matrix.size() - 1;
    while (l_idx < r_idx)
    {
      //Swap
      vector<int> temp = matrix[l_idx];
      matrix[l_idx] = matrix[r_idx];
      matrix[r_idx] = temp;

      //increment left and right index
      l_idx++;
      r_idx--;
    }

    //Iterating through the arrays to swap values
    int n = matrix.size();

    //Don't need to iterate over last array
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int_swap(matrix, matrix[i][j], matrix[j][i]);
      }
    }
  }
};