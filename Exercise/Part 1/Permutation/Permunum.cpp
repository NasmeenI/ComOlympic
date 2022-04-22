#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n+1];
    for(int i=1;i<=n;i++) cin >> arr[i];
    sort(arr+1 ,arr+1+n);

    do{
        for(int i=1;i<=n;i++) cout << arr[i] << ' ';
        cout << endl;
    }while(next_permutation(arr+1 ,arr+n+1));
}
