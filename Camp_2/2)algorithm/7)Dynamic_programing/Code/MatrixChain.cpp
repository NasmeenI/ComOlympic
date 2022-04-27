#include <bits/stdc++.h>
#define N 510
#define INF 1e9
using namespace std;

int n ,p[N];
vector<vector<int>> dp(N ,vector<int>(N ,INF));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<=n;i++) cin >> p[i];
    
    for(int z=1;z<=n;z++){
        for(int i=1;i<=n-z+1;i++){
            int j = i+z-1;
            if(z == 1){
                dp[i][j] = 0;
                continue;
            }
            for(int k=i;k<j;k++) dp[i][j] = min(dp[i][j] , dp[i][k]+dp[k+1][j]+(p[i-1]*p[k]*p[j]));
        }
    }
    cout << dp[1][n];
}
