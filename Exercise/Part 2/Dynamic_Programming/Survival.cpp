#include <bits/stdc++.h>
#define N 110
using namespace std;

int w ,si ,sj ,n ,dp[N][N][N];
float ans;
int di[]={-1 ,0 ,0 ,1} ,dj[]={0 ,-1 ,1 ,0};
//dp-> 0(not visit) ,1(false) ,2(survival)

int rec(int i ,int j ,int cnt){
    if(i<0 or i==w or j<0 or j==w) return 1;
    if(dp[i][j][cnt] == 2){
        ans++;
        return 2;
    }
    else if(dp[i][j][cnt]==1) return 1;

    if(cnt == n){
        ans++;
        return dp[i][j][cnt] = 2;
    }
    for(int k=0;k<4;k++){
        int goi = i+di[k] ,goj = j+dj[k];
        dp[i][j][cnt] = max(dp[i][j][cnt] ,rec(goi ,goj ,cnt+1));
    }
    return dp[i][j][cnt];
}

int main(){
    cin >> w >> si >> sj >>n;
    rec(si ,sj ,0);
    printf("%.6f",ans/4);
}
