//Candies Camp2/test2 2564
#include <bits/stdc++.h>
#define N 10010
using namespace std;

int n,ans;
vector<int> arr(N) ,cand(N ,1) ,dp(N ,1);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=n-1;i>=1;i--){
        if(arr[i] > arr[i+1]) dp[i] = dp[i+1] + 1;
        else dp[i] = max(dp[i+1] - 1 ,1);
    }

    for(int i=2;i<=n;i++){
        if(arr[i] > arr[i-1]) cand[i] = cand[i-1] + 1;
        else cand[i] = min(dp[i] ,cand[i-1] - 1);
    }

    for(int i=1;i<=n;i++) ans += cand[i];
    cout << ans;
}
/*
3
1 2 2

10
2 4 2 6 1 7 8 9 2 1

8
2 4 3 5 2 6 4 5
*/