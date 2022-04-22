#include <bits/stdc++.h>
using namespace std;

int n,m;
map<string,string> mymap;
map<string,pair<string,string>> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s,ip;
        cin >> s >> ip;
        mymap[ip] = s;
    }
    for(int i=0;i<m;i++){
        string s,ip,temps;
        cin >> s >> ip;

        auto it = mymap.find(ip);
        if(it != mymap.end()) temps = it->second;
        else temps = "error";

        ans[s] = {ip,temps};
    }
    for(auto e:ans) cout << e.first << " " << e.second.first << " #" << e.second.second << endl;
}
/*
2 2
main 192.168.0.2
replica 192.168.0.1
proxy 192.168.0.6
block 192.168.0.1
*/