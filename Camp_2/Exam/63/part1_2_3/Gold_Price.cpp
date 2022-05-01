#include <bits/stdc++.h>
#define N 1010
using namespace std;

int m,n;
vector<int> arr(N);
vector<vector<int>> dp(N/2 ,vector<int> (N ,0));

int F(int l ,int r){
    int mn = arr[l],mx=0;
    for(int i=l;i<=r;i++){
        mx = max(mx ,arr[i]-mn);
        mn = min(mn ,arr[i]);
    }
    return mx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=j;k++)
                dp[i][j] = max(dp[i][j] ,dp[i-1][k-1] + F(k ,j));
    
    cout << dp[m][n];
}
/*
2 6
100 220 50 750 650 800

3 8
10 50 20 30 70 60 40 50

2 5
1000 900 1200 1100 1000
*/