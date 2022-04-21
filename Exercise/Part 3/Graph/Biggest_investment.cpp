#include <bits/stdc++.h>
#define N 10010
using namespace std;

int n,m,ans;
float cost[N],mx;

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        float d;
        cin >> a >> b >> d;
        cost[a] += d/2;
        cost[b] += d/2;
    }
    for(int i=1;i<=n;i++){
       if(mx < cost[i]){
            mx = cost[i];
            ans = i;
       }
    }
    printf("%d %.2f",ans ,mx*5);
}
