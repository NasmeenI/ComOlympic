#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        for(int k=0;k<n;k++) for(int l=0;l<n;l++){
            if(i==j or i==k or i==l or j==k or j==l or k==l) continue;
            if(v[i]+v[j] == v[k]+v[l]){
                cout << v[i]+v[j];
                return 0;
            }
        }
    }
    cout << "not found";
}
