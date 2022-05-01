#include <bits/stdc++.h>
#define N 1010
#define INF 1e9
using namespace std;
using pi = pair<int,int>;

int n,m;
vector<int> G[N];
vector<vector<int>> dis(N ,vector<int> (N ,INF));

void STP(int start){
    vector<bool> vis(N ,false);
    priority_queue<pi ,vector<pi> ,greater<pi>> q;

    dis[start][start] = 0;
    q.push({dis[start][start] ,start});
    while(q.size()){
        int u = q.top().second;
        q.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(auto v:G[u]){
            if(!vis[v] and dis[start][v] > dis[start][u] + 1){
                dis[start][v] = dis[start][u] + 1;
                q.push({dis[start][v] ,v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<n;i++) STP(i); 
    
    int t;
    cin >> t;
    while(t--){
        int u,d,ans=0;
        cin >> u >> d;
        for(int i=0;i<n;i++){
            if(dis[u][i] == d) ans++;
        }
        cout << ans << endl;
    }
}
/*
9 10
1 2
2 3
1 7
2 4
3 4
4 7
7 8
0 7
7 6
5 6
3
4 2
5 3
2 1
*/