//SendMap Camp2/test2 2564
#include <bits/stdc++.h>
#define N 1010
#define INF 1e9
using namespace std;
using pi = pair<int,int>;

int n,m,total,can,ans;
int di[] = {-1 ,0 ,0 ,1} ,dj[] = {0 ,-1 ,1 ,0};
vector<vector<char>> arr(N ,vector<char> (N));
vector<vector<int>> dp(N ,vector<int> (N ,INF));
queue<pi> q;

struct data{
    vector<char> vec;
    int sum;
};

bool compare(const data &a ,const data &b){
    return a.sum < b.sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<data> v;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        data temp;
        temp.sum = 0;
        for(int j=1;j<=m;j++){
            int x;
            char y;
            cin >> x >> y;
            temp.sum += x;
            temp.vec.push_back(y);
            if(y == 'S') total++;
        }
        v.push_back(temp);
    }
    sort(v.begin() ,v.end() ,compare);

    vector<vector<char>> arr;
    for(auto e:v) arr.push_back(e.vec);
    
    dp[0][0] = 0;
    q.push({0 ,0});
    while(q.size()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(arr[i][j] == 'S'){
            can++;
            ans += dp[i][j];
        }

        for(int k=0;k<4;k++){
            int goi = i + di[k];
            int goj = j + dj[k];
            if(goi == n or goi < 0 or goj == m or goj < 0 or arr[goi][goj] == 'X') continue;

            if(dp[goi][goj] > dp[i][j] + 1){
                dp[goi][goj] = dp[i][j] + 1;
                q.push({goi ,goj});
            } 
        }
    }

    cout << ans << ' ' << total-can;
}
/*
3 3
2 C 7 C 5 C
4 S 3 X 9 C
8 C 6 S 1 X

4 4
13 C 6 C 12 S 3 S 
5 C 7 C 9 C 8 C 
14 C 2 C 16 C 15 X 
11 C 1 C 4 C 10 X

6 6
22 X 14 X 31 X 34 X 33 X 6 C 
26 C 11 X 12 X 4 C 19 X 20 S 
27 X 28 X 35 X 2 C 25 X 8 X 
21 C 23 X 9 X 32 X 15 X 3 C 
7 C 13 X 30 X 36 X 1 X 10 C 
24 S 29 C 16 X 5 X 18 X 17 X
*/