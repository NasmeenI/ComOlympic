#include <bits/stdc++.h>
#define N 510
using namespace std;

int n,w;
int val[N] ,wei[N] ,dp[N][N] ,item[N][N] ,nans ,wans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w;
    for(int i=1;i<=n;i++) cin >> wei[i];
    for(int i=1;i<=n;i++) cin >> val[i];

    for(int i=1;i<=n;i++){
        for(int wi=1;wi<=w;wi++){
            if(wei[i]<=wi and dp[i-1][wi] < val[i] + dp[i-1][wi-wei[i]]){
                dp[i][wi] = val[i] + dp[i-1][wi-wei[i]];
                item[i][wi] = 1;
            }
            else dp[i][wi] = dp[i-1][wi];
        }
    }
    int x = w;
    for(int i=n;i>0;i--){
        if(item[i][x]){
            nans++;
            wans += wei[i];
            x -= wei[i];
        }
    }
    cout << dp[n][w] << ' ' << nans << ' ' << wans;
}
