#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<string> ans;

void permutation(string s){
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin() ,s.end()));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> n;
    sort(s.begin() ,s.end());
    permutation(s);
    cout << ans[n-1];
}
