#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> ot;

struct data{
    ll start,stop;
};

bool compare(const data &a,const data &b){
    return a.stop < b.stop;
}

void room(){
    ll n;
    cin >> n;
    vector<data> v;
    for(ll i=0;i<n;i++){
        ll a;
        cin >> a;

        data temp;
        temp.start = a;
        v.push_back(temp);
    }
    for(ll i=0;i<n;i++){
        ll b;
        cin >> b;
        v[i].stop = v[i].start+b;
    }

    sort(v.begin( ),v.end() ,compare);
    ll cars = 1;
    while(1){
        ll x = v[0].stop;
        v.erase(v.begin());
        for(ll i=0;i<v.size();i++){
             if(x <= v[i].start){
                x = v[i].stop;
                v.erase(v.begin()+i);
                i--;
            }
            if(i+1 == v.size()){
                cars++;
            }
        }
        if(!v.size()) break;
    }
    ot.push_back(cars);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--) room();

    for(ll i=0;i<ot.size();i++) cout << ot[i] << endl;
}
/*
2
3
1 2 3
3 3 3
5
1 2 3 4 5
2 3 4 5 6
*/
