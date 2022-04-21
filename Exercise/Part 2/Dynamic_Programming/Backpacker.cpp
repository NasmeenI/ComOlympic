#include <bits/stdc++.h>
#define N 1010
#define INF 1e9
using namespace std;

int n ,arr[N][N];
vector<vector<int>> dp(N ,vector<int>(N ,INF));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> arr[i][j];

    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            dp[i][j] = arr[i][j];
            for(int k=i+1;k<=j-1;k++)
                dp[i][j] = min(dp[i][j] ,dp[i][k]+dp[k][j]);
        }
    }
    cout << dp[1][n];
}