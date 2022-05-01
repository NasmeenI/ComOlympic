#include <bits/stdc++.h>
#define N 1010
using namespace std;

int n,m,q,s,e;
vector<int> G[N];
vector<char> ans;

bool dfs(){
    vector<bool> vis(N ,false);
    stack<int> st;
    
    cin >> s >> e;
    st.push(s);
    while(st.size()){
        int u = st.top();
        st.pop();

        if(vis[u]) continue;
        vis[u] = true;
        if(u == e) return true;

        for(auto v:G[u]){
            if(!vis[v]) st.push(v);
        }
    }
    return false;
}

bool bfs(){
    vector<bool> vis(N ,false);
    queue<int> q;
    
    cin >> s >> e;
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();

        if(vis[u]) continue;
        vis[u] = true;
        if(u == e) return true;

        for(auto v:G[u]){
            if(!vis[v]) q.push(v);
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    while(q--){
        if(bfs()) ans.push_back('T'); //can use bfs or dfs
        else ans.push_back('F');
    }

    for(auto e:ans) cout << e;
}
/*
8 10 6
1 2
1 3
2 5
3 5
3 1
4 2
5 4
5 6
6 4
7 8
1 6
6 1
2 6
3 2
7 8
5 8

7 9 4
1 3
2 1
2 5
3 2
3 4
4 3
4 7
5 2
6 3
4 1
7 2
5 4
6 7
*/