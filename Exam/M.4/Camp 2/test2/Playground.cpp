#include <bits/stdc++.h>
#define N 2010
using namespace std;

int n,m,h,k,w,ans,mx=-1e9,nans;
int dp[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h >> w >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             cin >> dp[i][j];
             dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    int want = h*w*k;
    for(int i=h;i<=n;i++){
        for(int j=w;j<=m;j++){
            int area = dp[i][j]-dp[i-h][j]-dp[i][j-w]+dp[i-h][j-w];
            if(area > want) continue;
            if(area == mx) nans++;
            else if(area > mx){
                mx = area;
                ans = want-area;
                nans = 1;
            }
        }
    }
    cout << ans << ' ' << nans;
}