#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int ,vector<int> ,greater<int>> q;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        while(a--) q.push(b+i);
    }
    int day = 1;
    while(q.size()){
        int a = q.top();
        q.pop();
        if(a >= day) day++;
    }
    cout << day-1;
}
/*
5
1 3
2 2
3 1
5 4
2 2
*/
