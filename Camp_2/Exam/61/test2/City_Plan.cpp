#include <bits/stdc++.h>
#define N 1010
using namespace std;

int n,m,si,sj,ei,ej,pi,pj;
vector<vector<int>> dp(N ,vector<int>(N ,0));
vector<vector<int>> dp1(N ,vector<int>(N ,0));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    cin >> sj >> si;
    cin >> ej >> ei;
    cin >> pj >> pi;

    dp[si][sj] = 1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i-1 >= 0) dp[i][j] += dp[i-1][j];
            if(j-1 >= 0) dp[i][j] += dp[i][j-1];
        }
    }
    
    dp1[pi][pj] = dp[pi][pj];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i-1 >= 0) dp1[i][j] += dp1[i-1][j];
            if(j-1 >= 0) dp1[i][j] += dp1[i][j-1];
        }
    }
    cout << dp1[ei][ej];
}