#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> factor(ll a){
    vector<ll> v;
    while(a%2==0){
        v.push_back(2);
        a/=2;
    }
    for(ll i=3;i<=sqrt(a);i+=2){
        while(a%i==0){
            v.push_back(i);
            a/=i;
        }
    }
    if(a>2) v.push_back(a);
    return v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> v1,v2,v3;
    ll a,b;
    cin >> a >> b;
    v1 = factor(a);
    v2 = factor(b);

    for(auto e:v1) cout << e << ' ';
    cout << endl;
    for(auto e:v2) cout << e << ' ';

    for(ll i=0;i<v1.size();i++){
        for(ll j=0;j<v2.size();j++){
            if(v1[i]==-1 or v2[j]==-1) continue;
            if(v1[i]==v2[j]){
                v3.push_back(v1[i]);
                v1[i] = -1;
                v2[j] = -1;
            }
        }
    }
    cout << endl;
    if(!v3.size()){
        cout << "null";
        return 0;
    }
    for(auto e:v3) cout << e << " ";
}
