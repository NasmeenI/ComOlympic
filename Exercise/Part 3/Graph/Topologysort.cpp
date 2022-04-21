#include <bits/stdc++.h>
#define N 25
using namespace std;

int n,m,p;
int inde[N];
bool vis[N];
vector<int> G[N];
vector<int> seq;

void topo1(int u){
    if(vis[u]) return;
    vis[u] = true;

    seq.push_back(u);
    for(auto v:G[u]){
        inde[v]--;
        if(inde[v] == 0) topo1(v);
    }
}

void topo2(int u){
    queue<int> q;
    q.push(u);
    while(q.size()){
        int u = q.front();
        q.pop();
        seq.push_back(u);
        for(auto v:G[u]){
            inde[v]--;
            if(inde[v] == 0) q.push(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        inde[y]++;
    }
    for(int i=1;i<=n;i++){
        if(inde[i] == 0) p = i;
    }

    topo1(p);
    //topo2(p);
    for(auto e:seq) cout << e << ' ';
}
/*
7 7
4 1
4 5
4 6
1 2
2 3
5 3
6 7
*/
