class Solution
{
public:
  int orientation(vector<int> &B, vector<int> &A, vector<int> &T)
  {
    return ((T[1] - B[1]) * (B[0] - A[0]) - (B[1] - A[1]) * (T[0] - B[0]));
  }

  vector<vector<int>> outerTrees(vector<vector<int>> &trees)
  {
    sort(trees.begin(), trees.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); });
    int n = trees.size();
    vector<vector<int>> output;
    for (int i = 0; i < n; ++i)
    {
      while (size(output) > 1 && orientation(output[size(output) - 2], output.back(), trees[i]) < 0)
        output.pop_back();
      output.push_back(trees[i]);
    }
    // If all trees are along a line, size(output) is n after left to right procedure.
    if (size(output) == n)
      return output;

    // right to left
    for (int i = n - 2; i >= 0; --i)
    {
      while (size(output) > 1 && orientation(output[size(output) - 2], output.back(), trees[i]) < 0)
        output.pop_back();
      output.push_back(trees[i]);
    }
    output.pop_back();
    return output;
  }
};