#include <bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;

ll arr[N];

void fib(){
    ll k,n;
    cin >> n >> k;
    while(1){
        if(n == 1){
            cout << "N" << endl;
            break;
        }
        else if(n == 2){
            cout << "A" << endl;
            break;
        }

        if(k <= arr[n-2]) n -= 2;
        else if(k > arr[n-2]){
            k = k - arr[n-2];
            n--;
        } 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    arr[1] = arr[2] = 1;
    for(int i=3;i<=N;i++) arr[i] = arr[i-1] + arr[i-2];

    int t;
    cin >> t;
    while(t--) fib();
}