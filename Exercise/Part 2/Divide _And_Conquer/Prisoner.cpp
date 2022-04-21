#include <bits/stdc++.h>
#define N 1000010
using namespace std;

int n ,c ,t ,l ,r ,mid;
vector<int> v,ans;

int f(int x , int c  , int n){
    int p=1 ,l=v[0];
    for(int i=1;i<n;i++){
        if(v[i]-l >= x){
            p++;
            if(p == c) return 1;
            l = v[i];
        }
    }
    return 0;
}

void prisoner(){
    cin >> n >> c;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin() ,v.end());
    l=0 ,r = v[v.size()-1] - v[0] +1;
    while(r-l > 1){
        mid = ( r + l ) / 2;
        if(f(mid ,c ,n)) l = mid;
        else r = mid;
    }
    ans.push_back(l);
    v.clear();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) prisoner();
    for(auto e:ans) cout << e << endl;
}