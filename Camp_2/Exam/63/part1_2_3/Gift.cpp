#include <bits/stdc++.h>
#define N 110
#define W first
#define U second.first
#define V second.second
using namespace std;
using pi = pair<int,int>;
using ppi = pair<int,pi>;

int n,m;
vector<int> parent(N);

int root(int u){
    if(parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

int kruskal(vector<ppi> edges){
    int sum = 0;
    for(int i=1;i<=n;i++) parent[i] = i;
    sort(edges.begin() ,edges.end());
    for(auto edge:edges){
        int w = edge.W;
        int u = root(edge.U);
        int v = root(edge.V);
        if(w == -1 or u == v) continue;
        sum += w;
        parent[u] = v;
    }

    int x = root(1);
    for(int i=2;i<=n;i++){
        if(root(i) != x) sum = -1;
    }
    return sum;
}

void gift(){
    vector<ppi> edges;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({c ,{a ,b}});
    }

    for(int i=0;i<edges.size();i++){
        int temp = edges[i].W;
        edges[i].W = -1;
        cout << kruskal(edges) << endl;
        edges[i].W = temp;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) gift();
}
/*
1
5 7
1 2 2
1 4 4
2 3 6
2 5 8
3 5 10
4 3 12
1 5 14
*/