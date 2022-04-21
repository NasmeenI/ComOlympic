#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,ans;
    cin >> n >> m;
    float cost[n+1] ,mn=1e9;
    for(int i=0;i<=n;i++) cost[i] = 0;
    for(int i=0;i<m;i++){
        int a,b;
        float d;
        cin >> a >> b >> d;
        cost[a] += d/2;
        cost[b] += d/2;
    }
    for(int i=1;i<=n;i++){
       if(mn > cost[i]){
            mn = cost[i];
            ans = i;
       }
    }
    printf("%d %.2f",ans,mn*5);
}