#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n ,ans=0,mx=0;
    cin >> n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        int a; 
        cin >> a;
        m[a]++;
        if(mx < m[a]) mx = m[a] ,ans = a;
    }
    cout << ans;
}
