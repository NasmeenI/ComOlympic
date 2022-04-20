#include <bits/stdc++.h>
#define N 10010
using namespace std;

int n;
vector<int> arr(N) ,cand(N ,1);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=2;i<=n;i++){
        if(arr[i] > arr[i-1]) cand[i] = cand[i-1] + 1;
        else cand[i] = cand[i-1] - 1;
    }
}
/*
3
1 2 2

10
2 4 2 6 1 7 8 9 2 1

8
2 4 3 5 2 6 4 5
*/