#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    int arr[n+1];
    for(int i=1;i<=n;i++) arr[i] = i;
    set<int> s;
    for(int i=0,a;i<m;i++){
        cin >> a;
        s.insert(a);
    }
    do{
        bool ch = s.count(arr[1]);
        if(!ch){
            for(int i=1;i<=n;i++) cout << arr[i] << ' ';
            cout << endl;
        }
    }while(next_permutation(arr+1 ,arr+n+1));
}
/*
4
3
1 2 3
*/
