#include <bits/stdc++.h>
#define N 1010
using namespace std;

struct Edge{
    int u,v,w;
    bool operator<(const Edge &rhs) const{
        return w < rhs.w;
    }
};

int n,m,a,b,t;
int parent[N];
string s;
vector<Edge> edges;

int root(int u){
    if(parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

void merge(int u ,int v){
    u = root(u) ,v = root(v);
    if(u == v) return;

    if(u==0 or v==0){
        if(u == 0) parent[v] = 0;
        if(v == 0) parent[u] = 0;
    }
    else parent[u] = v;
}

void kruskal(){
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=0;i<n;i++) if(s[i]=='1') parent[i+1] = 0;

    sort(edges.begin() ,edges.end());
    int sum = 0;
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

    cin >> t;
    while(t--){
        cin >> n >> s >> a;
        edges.clear();
        for(int i=2;i<=n;i++){
            cin >> b;
            edges.push_back({i-1 ,i ,b-a});
            a = b;
        }
        kruskal();
    }
}