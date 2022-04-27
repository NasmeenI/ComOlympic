#include <bits/stdc++.h>
#define N 10010
using namespace std;
using pi = pair<int,int>;
using ppi = pair<int,pi>;

int n,m;
int parent[N];
vector<ppi> edges;

int root(int u){
    if(parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

void kruskal(){
    for(int i=1;i<=n;i++) parent[i] = i;
    sort(edges.begin() ,edges.end());
    int sum = 0;
    for(auto edge:edges){
        int w = edge.first;
        int u = root(edge.second.first);
        int v = root(edge.second.second);
        if(u == v) continue;
        parent[u] = v;
        sum += w;
    }
    cout << sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({c ,{a ,b}});
    }
    kruskal();
}