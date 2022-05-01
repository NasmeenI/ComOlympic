#include <iostream>
using namespace std;

bool has_in(char x ,string s){
    for(int i=0;i<s.size();i++){
        if(x == s[i]) return true;
    }
    return false;
}

void fun(){
    string s;
    int k;
    cin >> s >> k;

    int ans = 0;
    for(int i=0;i<s.size();i++){
        string s1;
        int num = 0;
        for(int j=i;j<s.size();j++){
            if(!has_in(s[j],s1) and num != k){
                s1.push_back(s[j]);
                num++;
                if(num == k) ans++;
            }
            else if(has_in(s[j],s1)){
                s1.push_back(s[j]);
                if(num == k) ans++;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) fun();
}