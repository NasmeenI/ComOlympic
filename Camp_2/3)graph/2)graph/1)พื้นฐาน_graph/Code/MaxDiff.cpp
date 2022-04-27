#include <bits/stdc++.h>
#define N 10010
using namespace std;

int n,m,mx,ans;
int ind[N] ,oud[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        ind[a]++;
        oud[b]++;
    }
    for(int i=1;i<=n;i++){
        int dif = abs(ind[i]-oud[i]);
        if(mx < dif){
            mx = dif;
            ans = i;
        }
    }
    cout << ans;
}