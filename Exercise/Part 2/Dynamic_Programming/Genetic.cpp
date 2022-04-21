#include <bits/stdc++.h>
#define N 102
using namespace std;

int dp[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1,s2;
    cin >> s1 >> s2;
    s1.insert(s1.begin() ,'0');
    s2.insert(s2.begin() ,'0');

    for(int i=1;i<s1.size();i++){
        for(int j=1;j<s2.size();j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                /*s1[i]='#';
                s2[j]='#';*/
            }
            else dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
        }
    }
    cout << dp[s1.size()-1][s2.size()-1];
}
