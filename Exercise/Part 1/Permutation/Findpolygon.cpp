#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = pow(2,n)-(pow(n,2)+n)/2-1;
    cout << ans;
}
