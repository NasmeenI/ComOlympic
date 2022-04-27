#include <bits/stdc++.h>
#define N 110
using namespace std;

int a,b;
float n,dp[N][N];

int main(){
    cin >> n >> a >> b;
    dp[1][1] = n;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(dp[i][j] >= 1){
                float w = (dp[i][j]-1)/2;
                dp[i][j] = 1;
                dp[i+1][j] += w;
                dp[i+1][j+1] += w;
            }
        }
    }
    float ans = ceil(dp[a][b]*100)/100;
    printf("%.2f",ans);
}
