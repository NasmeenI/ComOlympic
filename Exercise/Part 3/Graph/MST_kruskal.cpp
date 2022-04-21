#include <bits/stdc++.h>
#define N 10010
using namespace std;

struct Edge{
    int u,v,w;
    bool operator<(const Edge &rhs) const{
        return w < rhs.w;
    }
};

int n,m;
int parent[N] ,rnk[N];
vector<Edge> edges;

int root(int u){
    if(parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

void merge(int u ,int v){
    u = root(u) ,v = root(v);
    if(u == v) return;
    if(rnk[u] > rnk[v]){
        rnk[u] += rnk[v];
        parent[v] = u;
    }
    else{
        rnk[v] += rnk[u];
        parent[u] = v;
    }
}

void kruskal(){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        rnk[i] = 1;
    }
    sort(edges.begin() ,edges.end());
    int sum = 0;
    for(auto edge:edges){
        if(root(edge.u) == root(edge.v)) continue;
        sum += edge.w;
        merge(edge.u ,edge.v);
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
        edges.push_back({a ,b ,c});
    }
    kruskal();
}