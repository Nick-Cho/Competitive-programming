class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int l_ptr = 0;
    int r_ptr = height.size() - 1;
    int curr_area = 0;
    int max_area = 0;
    while (l_ptr < r_ptr)
    {
      curr_area = (r_ptr - l_ptr) * min(height[r_ptr], height[l_ptr]);
      if (curr_area > max_area)
      {
        max_area = curr_area;
      }
      if (height[l_ptr] < height[r_ptr])
      {
        l_ptr++;
      }
      else
      {
        r_ptr--;
      }
    }
    return max_area;
  }
};