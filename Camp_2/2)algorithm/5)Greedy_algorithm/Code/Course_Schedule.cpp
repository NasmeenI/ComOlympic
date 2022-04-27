#include <bits/stdc++.h>
using namespace std;

struct data{
    int time,finish;
};

bool compare(const data &a,const data &b){
    return a.finish < b.finish;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<data> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;

        data temp;
        temp.time = a;
        temp.finish = b;
        v.push_back(temp);
    }
    sort(v.begin() ,v.end() ,compare);

    int day = 0 ,c = 0;
    for(int i=0;i<v.size();i++){
        if(v[i].time+day <= v[i].finish){
            day = v[i].time+day;
            c++;
        }
    }
    cout << c;
}
/*
4
100 200
200 1300
1000 1250
2000 3200
*/
