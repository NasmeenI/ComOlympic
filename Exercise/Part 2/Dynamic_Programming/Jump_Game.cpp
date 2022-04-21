#include <bits/stdc++.h>
#define N 100010
using namespace std;

int n ,arr[N];
vector<int> dp(N,1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 0;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=arr[i];j++){
            if(i+j > n) break;
            dp[i+j] = min(dp[i+j] ,dp[i]+1);
        }
    }
    cout << dp[n];
}
