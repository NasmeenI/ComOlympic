#include <bits/stdc++.h>
#define INF 1e9
#define N 1e5+10
using namespace std;
using pi = pair<int,int>;

int n,m;
vector<vector<pi>> G(N);

void STP(){
	vector<int> dis(N ,INF);
	vector<bool> vis(N ,false);
	priority_queue<pi,vector<pi>,greater<pi>> q;

	int start = 1;
	dis[start] = 0;
	q.push({start ,dis[start]});
	while(!q.empty()){
		int u = q.top().first;
		q.pop();

		if(vis[u]) continue;
		vis[u] = true;

		for(auto e:G[u]){
			int v = e.first;
			int w = e.second;
			if(!vis[v] and dis[v]>dis[u]+w){
				dis[v] = dis[u]+w;
				q.push({v ,dis[v]});
			}
		}
	}
	for(int i=1;i<=n;i++) cout << dis[i] << ' ';
}

void MST(){
    vector<bool> vis(N ,false);
	vector<int> dis(N ,INF);
	priority_queue<pi,vector<pi>,greater<pi>> q;

	int start=1,sum=0;
	dis[start] = 0;
	q.push({dis[start] ,start});
	while(q.size()){
		int u = q.top().second;
		q.pop();

		if(vis[u]) continue;
		vis[u] = true;
		sum += dis[u];

		for(auto e:G[u]){
			int v = e.first;
			int w = e.second;
			if(!vis[v] and dis[v]>w){
				dis[v] = w;
				q.push({dis[v] ,v});
			}
		}
	}
	cout << sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		G[a].push_back({b ,c});
		G[b].push_back({a ,c});
	}
	//STP();
    MST();
}
/*
5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5
*/