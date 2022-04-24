#include <iostream>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int ans = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] >= '0' and s[i] <= '9') ans += s[i]-'0';
    }
    cout << ans;
}