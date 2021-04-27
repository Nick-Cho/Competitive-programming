#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, l1,l2,l3;
vector<vector<int>> arr;
int main(){
  cin >> n;
  for (int i = 0 ; i < n ; i++){
    cin >> l1>> l2 >>l3;
    arr.push_back({l1,l2,l3});
    sort(arr[0].begin(), arr[0].end());
  }
  for (int i = 0; i < n; i++){
    if (pow(arr[i][2],2) == pow(arr[i][1],2) + pow(arr[i][0],2)){
      cout << "R" <<endl;
    }
    else if (pow(arr[i][2],2) < (pow(arr[i][1],2) + pow(arr[i][0],2))){
      cout << "A" << endl;
    }
    else if (pow(arr[i][2],2) > pow(arr[i][1],2) + pow(arr[i][0],2)){
      cout << "O" << endl;
    }
  }
}