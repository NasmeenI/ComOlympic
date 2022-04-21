#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int sum ,n;
    cin >> sum >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]+v[j] == sum){
                cout << min(v[i] ,v[j]) << ' ' << max(v[i] ,v[j]);
                return 0;
            }
        }
    }
    cout << "not found";
}
