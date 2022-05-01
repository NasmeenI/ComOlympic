#include <bits/stdc++.h>
#define N 1010
#define INF 1e9
using namespace std;
using pi = pair<int,int>;
using ppi = pair<pi,int>;

int n,m,s,e,k;
vector<pi> G[N];
vector<bool> node(N ,false);
vector<vector<int>> dis(N ,vector<int>(2 ,INF));
priority_queue<ppi ,vector<ppi> ,greater<ppi>> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s >> e;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({c ,b});
        G[b].push_back({c ,a});
    }
    cin >> k;
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        node[x] = true;
    }

    dis[s][0] = 0;
    q.push({{dis[s][0] ,s} ,0});
    while(q.size()){
        int u = q.top().first.second;
        int st = q.top().second;
        q.pop();

        for(auto e:G[u]){
            int w = e.first;
            int v = e.second;
            if(dis[v][st] > dis[u][st] + w){
                dis[v][st] = dis[u][st] + w;
                q.push({{dis[v][st] ,v} ,st});
            }
            if(node[v] and dis[v][1] > dis[u][st] + w){
                dis[v][1] = dis[u][st] + w;
                q.push({{dis[v][1] ,v} ,1});
            }
        }
    }
    cout << dis[e][1]+5;
}
/*
9 14 9 4
9 1 4
9 7 8
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
3
3
1
8
*/