#include <iostream>
#include<algorithm>
using namespace std;
int houses[100010], a, b, s, sum = 0;

int main(){
    int N,L,S;
    cin >> N >> L >> S;

    memset(houses, 0, sizeof(houses));
    
    for (int i = 0; i<N; i++){
        cin >> a >> b >> s;
        for (int j = a-1; j<b; j++){
            houses[j] += s;
        }
    }    
    for (int i=0; i < L; i++){
        if (houses[i] < S){
            sum++;
        }
    }
    cout << sum;
}