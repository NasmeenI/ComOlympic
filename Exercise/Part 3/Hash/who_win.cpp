#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        int a; 
        cin >> a;
        m[a]++;
    }
    cout << m.size()%2+1;
}