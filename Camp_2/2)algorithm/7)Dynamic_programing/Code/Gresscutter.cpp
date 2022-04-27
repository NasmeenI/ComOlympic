#include <bits/stdc++.h>
#define N 1010
#define INF 1e9
using namespace std;

int n ,m ,arr[N];
vector<vector<int>> dp(N ,vector<int>(N ,INF));

int F(int i ,int j){
    int sum = 0;
    for(int k=i;k<=j;k++) sum += arr[k];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=m;i++) cin >> arr[i];

    dp[0][0] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=j;k++)
                dp[i][j] = min(dp[i][j] , max(dp[i-1][k-1] ,F(k,j)));

    cout << dp[n][m];
}
