#include <bits/stdc++.h>
#define N 1010
using namespace std;

int n,m,si,sj,ei,ej,ri,rj;
bool st;
vector<vector<int>> dp(N ,vector<int>(N ,0));
vector<vector<bool>> vis(N ,vector<bool>(N ,false));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> sj >> si >> ej >> ei >> rj >> ri;
    si++,sj++,ei++,ej++,ri++,rj++;

    for(int i=si;i<=n+1;i++){
        for(int j=sj;j<=m+1;j++){
            if(i==si and j==sj) dp[i][j] = 1;
            if(st == 0) dp[i][j] += dp[i-1][j]+dp[i][j-1];
            else{
                dp[i][j] += vis[i-1][j] ? dp[i-1][j] : 0;
                dp[i][j] += vis[i][j-1] ? dp[i][j-1] : 0;
                vis[i][j] = true;
            }
            if(i==ri and j==rj){
                vis[i][j] = true;
                st = true;
            }
        }
    }
    cout << dp[ei][ej];
}
