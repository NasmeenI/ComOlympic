#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct data{
    int s,f;
};

bool compare(const data &a,const data &b){
    return a.f < b.f;
}

int main(){
    int n;
    cin >> n;
    vector<data> v,ot;
    for(int i=0;i<n;i++){
        data temp;
        cin >> temp.s >> temp.f;
        v.push_back(temp);
    }
    sort(v.begin() ,v.end() ,compare);

    data temp;
    int x = v[0].f;
    temp.s = v[0].s;
    temp.f = v[0].f;
    ot.push_back(temp);
    for(int i=1;i<v.size();i++){
        if(v[i].s >= x){
            temp.s = v[i].s;
            temp.f = v[i].f;
            x = v[i].f;
            ot.push_back(temp);
        }
    }
    cout << ot.size() << endl;
    for(vector<data>::iterator it=ot.begin();it!=ot.end();it++){
        cout << it->s << " " << it->f << endl;
    }
}
/*
11
0 6
1 4
2 13
3 5
3 8
5 7
5 9
6 10
8 11
8 12
12 14
*/
