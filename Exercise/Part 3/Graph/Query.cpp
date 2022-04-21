#include <bits/stdc++.h>
#define N 10010
using namespace std;

struct Edge{
    int u,v,sw,w;
    bool operator<(const Edge &rhs) const{
        return w < rhs.w;
    }
};

int n,m,q;
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
    cout << sum << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a ,b ,c ,c});
    }
    while(q--){
        int x,y,z;
        cin >> x;
        if(x == 3){
            kruskal();
            continue;
        }
        cin >> y >> z;
        if(x == 1){
            for(int i=0;i<m;i++){
                if(edges[i].u!=y or edges[i].v!=z) continue;
                edges[i].w = 0;
                break;
            }
        }
        else if(x == 2){
            for(int i=0;i<m;i++){
                if(edges[i].u!=y or edges[i].v!=z) continue;
                edges[i].w = edges[i].sw;
                break;
            }
        }
    }
}
/*
4 4 5
1 2 1
2 3 1
3 4 1
4 1 1
3
1 1 2
3
2 1 2
3
*/
