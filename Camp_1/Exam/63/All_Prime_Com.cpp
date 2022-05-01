#include <iostream> //c++
#include <vector> //vector in Camp2
#include <cmath> //use sqrt
#define ll long long 
using namespace std;

void primeFactors(ll n ,vector<ll> &v){
    while(n % 2 == 0){
        v.push_back(2);
        n /= 2;
    }

    for(int i=3;i<=sqrt(n);i+=2){
        while (n % i == 0){
            v.push_back(i);
            n /= i;
        }
    }
    if(n > 2) v.push_back(n);

    //print
    for(int i=0;i<v.size();i++) cout << v[i] << ' ';
    cout << endl;
}

int main(){
    ll a,b;
    vector<ll> va,vb,vc;
    cin >> a >> b;

    primeFactors(a ,va);
    primeFactors(b ,vb);

    for(int i=0;i<va.size();i++){
        for(int j=0;j<vb.size();j++){
            if(va[i] == vb[j]){
                vc.push_back(va[i]);
                vb[j] = -1;
                break;
            }
        }
    }
    if(vc.size()){
        for(int i=0;i<vc.size();i++) cout << vc[i] << ' ';
    }
    else cout << "null";
}