#include <bits/stdc++.h>
using namespace std;

int n,ans;

void rec(int i){
    if(i == n){
        ans++;
        return ;
    }

    if(i+1 <= n) rec(i+1);
    if(i+2 <= n) rec(i+2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    rec(0);
    cout << ans;
}