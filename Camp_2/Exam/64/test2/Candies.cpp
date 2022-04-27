#include <bits/stdc++.h>
#define N 10010
using namespace std;

int n,ans;
vector<int> arr(N) ,cand(N);

void divide(int l ,int r){
    if(l == r){
        cand[l] = 1;
        return ;
    }

    int m = (l+r)/2;
    divide(l ,m);
    divide(m+1 ,r);

    if(arr[m] > arr[m+1] or arr[m] == arr[m+1]){
        if(cand[m] < cand[m+1] or cand[m] == cand[m+1]){
            int dif = cand[m+1] - cand[m] + 1;
            for(int i=l;i<=m;i++){
                if(arr[i] < arr[i+1]) break;
                cand[i] += dif;
            }
        }
    }
    else if(arr[m] < arr[m+1]){
        if(cand[m] > cand[m+1] or cand[m] == cand[m+1]){
            int dif = cand[m] - cand[m+1] + 1;
            for(int i=m+1;i<=r;i++){
                if(arr[i-1] > arr[i] or arr[i-1] == arr[i]) break;
                cand[i] += dif;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
     
    divide(1 ,n);
    for(int i=1;i<=n;i++) ans += cand[i];
    cout << ans;
}
/*
3
1 2 2

10
2 4 2 6 1 7 8 9 2 1

8
2 4 3 5 2 6 4 5
*/