#include <bits/stdc++.h>
#define N 1010
using namespace std;

int n,m,dp[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> dp[i][j];
            dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    int x = max(n,m);
    for(int k=x;k>0;k--){
        for(int i=k;i<=n;i++){
            for(int j=k;j<=m;j++){
                int area = dp[i][j]-dp[i][j-k]-dp[i-k][j]+dp[i-k][j-k];
                if(area == pow(k,2)){
                    cout << k;
                    return 0;
                }
            }
        }
    }
    cout << 0;
}
/*
5 5
0 0 0 0 1
0 1 1 1 1
0 1 1 1 0
1 0 1 0 0
1 0 0 1 1
*/
