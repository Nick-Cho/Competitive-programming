class Solution
{
public:
  int fibSum(int n, int &count, int num1, int num2)
  {
    if (count == n)
    {
      return num2;
    }
    else
    {
      count++;
      return fibSum(n, count, num2, num1 + num2);
    }
  }
  int fib(int n)
  {
    if (n == 0)
      return 0;
    int count = 1;
    return fibSum(n, count, 0, 1);
  }
};