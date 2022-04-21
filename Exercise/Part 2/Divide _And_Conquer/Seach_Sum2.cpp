//Incomplete
#include <bits/stdc++.h>
#define N 1000010
using namespace std;
using pi = pair<int,int>;

int n ,k ,arr[N];
vector<int> v(N,1e9+10);

pi divide(int l ,int r){
    if(l == r){
        if(v[1] > arr[l]) v[1] = arr[l];
        return {arr[l] ,1};
    }

    int mid = (l+r)/2;
    pi pl = divide(l,mid);
    pi pr = divide(mid+1,r);

    int vall = pl.first;
    int nl = pl.second;
    int cnt = 1;
    for(int i=mid+1;i<=r;i++){
        if(v[nl+cnt] > vall+arr[i]){
            v[nl+cnt] = vall+arr[i];
        }
        cnt++;
        vall += arr[i];
    }

    int valr = pr.first;
    int nr = pr.second;
    cnt = 1;
    for(int i=mid;i>=l;i--){
        if(v[nr+cnt] > valr+arr[i]){
            v[nr+cnt] = valr+arr[i];
        }
        cnt++;
        valr += arr[i];
    }

    return {pl.first+pr.first ,pl.second+pr.second};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    v[0] = 0;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    divide(0,n-1);

    while(k--){
        int a; 
        cin >> a;
        int ans = upper_bound(v.begin(),v.end(),a)-v.begin()-1;
        cout << ans << endl;
    }
}
