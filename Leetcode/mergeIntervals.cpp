class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    //sort based off of sub array's first index
    sort(intervals.begin(), intervals.end());
    if (intervals.size() <= 1)
    {
      return intervals;
    }
    vector<vector<int>> s;
    s.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
      vector<int> interval = s.back();
      //condition for no overlap
      if (interval[1] < intervals[i][0])
      {
        s.push_back(intervals[i]);
      }
      else if (interval[1] < intervals[i][1])
      {
        interval[1] = intervals[i][1];
        s.pop_back();
        s.push_back(interval);
      }
    }
    return s;
  }
};