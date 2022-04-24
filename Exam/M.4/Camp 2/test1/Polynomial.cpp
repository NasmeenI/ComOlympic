#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    queue<pi> q1,q2;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        q1.push({a ,b});
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        q2.push({a ,b});
    }

    while(q1.size() or q2.size()){
        if(!q1.size()){
            while(q2.size()){
                cout << q2.front().first << ' ' << q2.front().second << ' ';
                q2.pop();
            }
            return 0;
        }
        else if(!q2.size()){
            while(q1.size()){
                cout << q1.front().first << ' ' << q1.front().second << ' ';
                q1.pop();
            }
            return 0;
        }

        if(q1.front().second > q2.front().second){
            cout << q1.front().first << ' ' << q1.front().second << ' ';
            q1.pop();
        }
        else if(q1.front().second < q2.front().second){
            cout << q2.front().first << ' ' << q2.front().second << ' ';
            q2.pop();
        }
        else{
            int temp = q1.front().first + q2.front().first;
            if(temp != 0) cout << temp << ' ' << q1.front().second << ' ';
            q1.pop();
            q2.pop();
        }
    }
}
/* 
4 3
3 5 5 2 -3 1 8 0
2 4 -3 2 9 0

4 3
3 5 5 2 -3 1 8 0
2 4 -5 2 9 0

4 2
3 5 5 2 -3 1 8 0
2 4 -3 2
out put -> 3 5 2 4 2 2 -3 1 8 0
*/
