class Solution
{
public:
  void findWinner(vector<int> &v, int i, int k)
  {
    if (v.size() == 1)
      return;
    i = (i + k - 1) % v.size();
    v.erase(v.begin() + i);
    findWinner(v, i, k);
  }
  int findTheWinner(int n, int k)
  {

    vector<int> v;
    for (int i = 1; i <= n; i++)
      v.push_back(i);

    findWinner(v, 0, k);

    return v[0];
  }
};
