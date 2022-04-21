#include <bits/stdc++.h>
#define N 105
using namespace std;

int n ,mx ,arr[N] ,dp[N] ,dp2[N] ,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=1;i<=n;i++){
        if(arr[i] < mx) dp[i] = mx-arr[i];
        else if(arr[i] > mx) mx = arr[i];
    }
    mx = 0;
    for(int i=n;i>0;i--){
        if(arr[i] >= mx){
            mx = arr[i];
            dp[i] = 0;
        }
        else if(arr[i] < mx) dp[i] = min(dp[i] ,mx-arr[i]);
    }
    for(int i=1;i<=n;i++) ans += dp[i];
    cout << ans;
}

