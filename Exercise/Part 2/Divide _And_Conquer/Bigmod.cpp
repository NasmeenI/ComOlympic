#include <bits/stdc++.h>
using namespace std;

int divide(int b ,int p ,int m){
    if(p == 1) return b % m;
    return ( divide(b ,p/2 ,m) * divide(b ,(p&1? p/2+1:p/2) ,m) )%m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int b,p,m;
        cin >> b >> p >> m;
        cout << divide(b ,p ,m) << endl;
    }
}
