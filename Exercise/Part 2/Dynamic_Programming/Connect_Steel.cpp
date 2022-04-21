#include <bits/stdc++.h>
#define N 1010
using namespace std;

int n ,arr[N] ,cost[N][N] ,len[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //input
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    //base case
    sort(arr+1 ,arr+n+1);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cost[i][j] = 1e9;
    for(int i=1;i<=n;i++) cost[i][i] = 0 ,len[i][i] = arr[i];

    //Recurrence
    for(int i=n-1;i>0;i--){
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<j;k++){
                cost[i][j] = min(cost[i][j] ,cost[i][k] + len[i][k] + cost[k+1][j] + len[k+1][j]);
            }
            for(int k=i;k<=j;k++) len[i][j] += arr[k];
        }
    }
    cout << cost[1][n];
}
