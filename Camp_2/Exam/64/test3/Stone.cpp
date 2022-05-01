#include <bits/stdc++.h>
#define N 1010
using namespace std;
using pi = pair<int,int>;
using ppi = pair<int,pi>;

int n,m,k,sum;
vector<int> parent(N);
vector<ppi> edges;

int root(int u){
    if(parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({c ,{a ,b}});
    }
    
    sort(edges.begin() ,edges.end());
    for(int i=0;i<n;i++) parent[i] = i;
    for(auto edge:edges){
        int w = edge.first;
        int u = root(edge.second.first);
        int v = root(edge.second.second);
        if(u == v) continue;
        sum += w;
        parent[u] = v;

        set<int> s;
        for(int i=0;i<n;i++) s.insert(root(parent[i]));
        if(s.size() == k) break;
    }
    cout << sum;
}
/*
9 14 3
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 8 2
8 6 6
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
5 4 10
*/