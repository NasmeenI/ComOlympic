//n-Cubes Camp2/test2 2564
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve(int i){
    if(i == n){
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0'){
                cout << s << "-";
                s[i] = '1';
                cout << s << endl;
                s[i] = '0';
            }
        } 
        return;
    }

    s += '0';
    solve(i+1);
    s.pop_back();
    
    s += '1';
    solve(i+1);
    s.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    solve(0);
}