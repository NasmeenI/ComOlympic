#include <bits/stdc++.h>
using namespace std;

struct data{
    char id;
    int deadline,profit;
};

bool compare(const data &a,const data &b){
    return a.profit > b.profit;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,mx=0;
    cin >> n;
    vector<data> v;
    for(int i=0;i<n;i++){
        char in_id;
        int in_deadline,in_profit;
        cin >> in_id >> in_deadline >> in_profit;

        mx = max(mx ,in_deadline);
        data temp;
        temp.id = in_id;
        temp.deadline = in_deadline;
        temp.profit = in_profit;
        v.push_back(temp);
    }

    char timeline[mx+1];
    for(int i=1;i<=mx;i++) timeline[i] = '0';

    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        int j = 0;
        while(1){
            if(timeline[v[i].deadline-j] == '0'){
                timeline[v[i].deadline-j] = v[i].id;
                break;
            }
            if(v[i].deadline-j == 1) break;
            j++;
        }
    }
    for(int i=1;i<=mx;i++){
        if(timeline[i] != '0') cout << timeline[i] << ' ';
    }
}
/*
4
a 4 20
b 1 10
c 1 40
d 1 30

5
a 2 100
b 1 19
c 2 27
d 1 25
e 3 15
*/
