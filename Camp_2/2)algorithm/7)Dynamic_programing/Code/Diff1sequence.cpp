#include <bits/stdc++.h>
#define N 110
#define ar array
using namespace std;

int n,arr[N][N],dp[N][N],ans=-1e9,pi,pj;
ar<ar<vector<int>,N>,N> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> arr[i][j];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a=0 ,b=0;
            if(abs(arr[i-1][j]-arr[i][j]) == 1) a = dp[i-1][j]+1;
            if(abs(arr[i][j-1]-arr[i][j]) == 1) b = dp[i][j-1]+1;
            dp[i][j] = max(a,b);
            if(ans < dp[i][j]){
                ans = dp[i][j];
                pi = i;
                pj = j;
            }

            if(dp[i][j] == 0) dp[i][j] = 1;
            else if(dp[i][j] == a) v[i][j] = v[i-1][j];
            else if(dp[i][j] == b) v[i][j] = v[i][j-1];
            v[i][j].push_back(arr[i][j]);
        }
    }
    for(auto e:v[pi][pj]) cout << e << ' ';
    cout << endl;
    cout << (ans>0 ? ans-1 : 0);
}
