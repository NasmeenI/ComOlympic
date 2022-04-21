#include <bits/stdc++.h>
#define N 5
using namespace std;

void printhTable(list<int>hList[]){
    for(int i=0;i<N;i++){
        cout << i << ": ";
        for(auto it=hList[i].begin(); it!=hList[i].end(); it++) cout << *it << " ";
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    list<int> hTable[N];
    for(int i=0;i<10;i++){
        cin >> num;
        hTable[num%N].push_back(num);
    }
    printhTable(hTable);
    return 0;
}
