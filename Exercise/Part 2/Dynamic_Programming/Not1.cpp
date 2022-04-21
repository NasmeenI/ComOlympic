#include <bits/stdc++.h>
#define N 1010
using namespace std;

int n;
vector<vector<int>> dp(N ,vector<int>(N));

void rec(deque<int> q ,int x){
    if(x == n){
        q.pop_front();
        deque<int> q1 = q;
        int a;
        if(q.back()==0) a = 2;
        else a = 1;

        while(q.size()){
            cout << q.front();
            q.pop_front();
        }
        cout << 0 << ' ';
        if(a == 1) return ;

        while(q1.size()){
            cout << q1.front();
            q1.pop_front();
        }
        cout << 1 << ' ';
        return ;
    }
    q.push_back(0);
    rec(q,x+1);
    q.pop_back();

    if(q.back() == 1) return ;
    q.push_back(1);
    rec(q,x+1);
    q.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    cout << dp[n][0] + dp[n][1];

    /* Note
    deque<int> q; 
    q.push_back(0);
    rec(q,1);
    cout << endl;
    */
}
