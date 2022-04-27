#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k,ans=0;
    cin >> n >> k;
    int arr[n+1];
    for(int i=1;i<=n;i++) arr[i] = i;
    do{
        string s;
        for(int i=1;i<=n;i++) s += arr[i]+'0';
        int sum = stoi(s);
        if(sum > k) ans++;
    }while(next_permutation(arr+1 ,arr+n+1));
    cout << ans;
}
