#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    vector<vector<int>> houses;
    int N,L,S;
    int  a, b, s, sum = 0;
    cin >> N >> L >> S;
    sum = L;
    for (int i = 0; i<N; i++){
        cin >> a >> b >> s;
        houses.push_back({a,s});
        houses.push_back({b+1,-s});
        //houses[a][0] = a; houses[a][1] = s; houses[b][0] = b; houses [b][1] = -s;
        //cout << houses[i][0]<< houses[i][1]<< houses[i+1][0] << houses [i+1][1];
    }    
    sort(houses.begin(), houses.end(), [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });
    for (int i = 0; i < (2*N-1); i++){
        houses[i+1][1] += houses[i][1];
        if (houses[i][1] >= S){
            sum -= (houses[i+1][0] - houses[i][0]);
        }
    }
    // for (int i = 0; i < 9999; i++){
    //     if (i == 0){
    //         arr[0] += houses[0][1];
    //         if (arr[0] < S){
    //             sum++;
    //         }
    //     }
    //     else{
    //         arr[i] += (houses[i][1] + arr[i-1]);
    //         if (arr[i] < S){
    //             sum++;
    //         }
    //     }
    // }
    // for (int i=0; i < L; i++){
    //     if (houses[i] < S){
    //         sum++;
    //     }
    // }
    cout << sum;
    return 0;
}
