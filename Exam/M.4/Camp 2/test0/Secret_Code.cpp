#include <iostream>
using namespace std;

string s;

void f(){
    int ans1=0,ans2=0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'i') ans1++;
        if(s[i] >= '0' and s[i] <= '9') ans2 += s[i]-'0';
    }
    cout << ans1 << ans2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    getline(cin,s);
    f();
}