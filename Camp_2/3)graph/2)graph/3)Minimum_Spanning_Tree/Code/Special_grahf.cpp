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
    if(parent[u]==u) return u;
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
    sort(edges.begin(),edges.end());
    int sum=0;
    for(auto edge:edges){
        if(root(edge.u) == root(edge.v)) continue;
        sum += edge.w;
        merge(edge.u,edge.v);
    }
    cout << sum << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            edges.push_back({i ,j ,0});
        }
    }
    while(m--){
        int a,b;
        cin >> a >> b;
        for(int i=0;i<edges.size();i++){
            if(edges[i].u!=a or edges[i].v!=b) continue;
            edges[i].w = 1;
        }
    }
    kruskal();
}
/*
6 11
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6
*/
