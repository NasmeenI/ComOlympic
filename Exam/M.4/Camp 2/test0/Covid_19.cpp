#include <bits/stdc++.h>
#define N 110
#define INF 1e9
using namespace std;
using pi = pair<int,int>;

int di_H[] = {-1 ,-1 ,-1 ,0 ,0 ,1 ,1 ,1} ,dj_H[] = {-1 ,0 ,1 ,-1 ,1 ,-1 ,0 ,1};
vector<vector<int>> dis_H(N ,vector<int>(N ,INF));
vector<vector<int>> dis_S(N ,vector<int>(N ,INF));
vector<pi> v;
queue<pi> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m,n,k;
    cin >> m >> n >> k;
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a ,b});
    }

    for(auto e:v){
        vector<vector<int>> dis_S2(N ,vector<int>(N ,INF));
        dis_S2[e.first][e.second] = 1;
        for(int i=1;i<=m;i++){
            if(e.first+i > m) break;
            dis_S2[e.first+i][e.second] = dis_S2[e.first+i-1][e.second] + 1;
        }
        for(int i=1;i<=m;i++){
            if(e.first-i == 0) break;
            dis_S2[e.first-i][e.second] = dis_S2[e.first-i+1][e.second] + 1;
        }
        for(int j=1;j<=n;j++){
            if(e.second+j > n) break;
            dis_S2[e.first][e.second+j] = dis_S2[e.first][e.second+j-1] + 1;
        }
        for(int j=1;j<=n;j++){
            if(e.second-j == 0) break;
            dis_S2[e.first][e.second-j] = dis_S2[e.first][e.second-j+1] + 1;
        }

        for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) dis_S[i][j] = min(dis_S[i][j] ,dis_S2[i][j]);
    }


    int ans = 0;
    dis_H[1][1] = 1;
    q.push({1 ,1});
    while(q.size()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(dis_H[i][j] < dis_S[i][j]){
            ans++;
            //cout << i << ' ' << j << endl;
        }
        
        for(int k1=0;k1<8;k1++){
           int goi = i + di_H[k1];
           int goj = j + dj_H[k1];
           if(goi==0 or goi>m or goj==0 or goj>n) continue;
           if(dis_H[goi][goj] > dis_H[i][j]+1){
               dis_H[goi][goj] = dis_H[i][j]+1;
               q.push({goi ,goj});
           }
       }
    }
    cout << ans;
}