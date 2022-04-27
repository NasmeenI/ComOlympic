#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        map<char,int> m;
        priority_queue<char,vector<char>,greater<char>> q;
        string a,b;
        cin >> a >> b;
        for(int i=0;i<a.size();i++) m[a[i]]++;
        for(int i=0;i<b.size();i++){
            if(m[b[i]]){
                q.push(b[i]);
                m[b[i]]--;
            }
        }
        while(q.size()){
            cout << q.top();
            q.pop();
        }
        cout << endl;
    }
}
/*
3
pretty
women
walking
down
thespeed
street
*/
