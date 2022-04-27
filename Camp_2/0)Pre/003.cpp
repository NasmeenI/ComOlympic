#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct data{
    string name;
    int age,height;
};

bool comparename(const data &a,const data &b){
    return a.name>b.name;
}

bool compareage(const data &a,const data &b){
    return a.age>b.age;
}

bool compareheight(const data &a,const data &b){
    return a.height>b.height;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<data> v;
    for(int i=0;i<n;i++){
        data temp;
        cin >> temp.name >> temp.age >> temp.height;
        v.push_back(temp);
    }
    if(m == 1) sort(v.begin() ,v.end() ,comparename);
    else if(m == 2) sort(v.begin() ,v.end() ,compareage);
    else sort(v.begin() ,v.end() ,compareheight);

    for(auto it=v.begin();it!=v.end();it++) cout << it->name << " " << it->age << " " << it->height << endl;
}
/*
5 2
Steve 55 162
Beck 82 184
Alex 60 170
Jarvis 76 478
Toni 85 180
*/

