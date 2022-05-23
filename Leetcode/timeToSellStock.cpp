class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int output = 0;
    int min = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
      // Check if new profit > old profit
      if (output < (prices[i] - min))
        output = prices[i] - min;
      if (prices[i] < min)
      {
        min = prices[i];
      }
    }
    return output;
  }
};