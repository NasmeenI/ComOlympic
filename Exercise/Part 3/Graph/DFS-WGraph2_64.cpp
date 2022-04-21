#include <bits/stdc++.h>
#define N 1010
using namespace std;
using pi = pair<int,int>;

int n,m,s;
vector<int> parent(N) ,dis(N);
vector<pi> G[N];
vector<bool> vis(N ,false);

void dfs(){
    parent[s] = s;
    stack<int> st;
    st.push(s);
    while(st.size()){
        int u = st.top();
        st.pop();

        if(vis[u]) continue;
        vis[u] = true;

        cout << u << ' ';
        for(auto e:G[u]){
            int v = e.first;
            int w = e.second;
            if(!vis[v]){
                st.push(v);
                parent[v] = u;         // parent
                dis[v] = dis[u] + w;   // dis
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b ,c});
        G[b].push_back({a ,c});
    }

    dfs();
    cout << endl;
    for(int i=1;i<=n;i++) cout << parent[i] << ' ';
    cout << endl;
    for(int i=1;i<=n;i++) cout << dis[i] << ' ';
}
/*
8 12 1
1 2 4
1 3 3
2 3 2
2 4 5
3 4 3
3 5 6
4 5 1
4 6 5
5 7 5
6 7 2
6 8 7
7 8 4
*/