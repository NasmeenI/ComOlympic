#include <bits/stdc++.h>
using namespace std;

int n;
map<string,int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        string s;
        cin >> s;
        m[s]++;
    }
    for(auto e:m) cout << e.first << " " << e.second << endl;
}
/*
10
paris
tokyo
london
hawaii
mosco
tokyo
london
tokyo
paris
paris
*/