#include <bits/stdc++.h>
using namespace std;

void f(){
    int n;
    cin >> n;
    vector<int> v1,v2;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }
    sort(v1.begin() ,v1.end());
    sort(v2.begin() ,v2.end());

    if(v1 == v2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) f();
}