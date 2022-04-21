#include <bits/stdc++.h>
using namespace std;

struct data{
    int time,round;
};

vector<data> ot;

void ferry(){
    int n,t,m;
    cin >> n >> t >> m;
    vector<int> v;
    for(int i=0;i<m;i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
    }

    int time = 0 ,round = 0;
    while(1){
        if(v.size() >= n){
            time += t+v[n-1]-time;
            round++;
            for(int i=0;i<n;i++) v.erase(v.begin());
        }
        else{
            time += v[v.size()-1]+t-time;
            round++;
            break;
        }
        if(!v.size()) break;
    }
    data temp;
    temp.time = time;
    temp.round = round;
    ot.push_back(temp);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) ferry();
        
    for(int i=0;i<ot.size();i++) cout << ot[i].time << ' ' << ot[i].round << endl;
}
/*
2
2 10 10
0
10
20
30
40
50
60
70
80
90
2 10 3
10
30
40
*/
