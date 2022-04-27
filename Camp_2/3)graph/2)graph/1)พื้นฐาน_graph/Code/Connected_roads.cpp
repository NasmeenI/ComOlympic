#include <bits/stdc++.h>
#define N 10010
using namespace std;
using pi = pair<int,int>;

int n,m;
float cost[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        float d;
        cin >> a >> b >> d;
        cost[a] += d;
    }
    vector<pi> v;
    for(int i=1;i<=n;i++){
        v.push_back({cost[i] ,i});
    }
    sort(v.begin() ,v.end());
    for(auto e:v) cout << e.second << ' ' << e.first << endl;
}
