#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h,m;
    cin >> h >> m;
    int dm = m*(360/60) ;
    int dh = ( h*(360/12) + (m*360)/(12*60))%360;
    cout << abs(dm-dh);
}
