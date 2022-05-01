#include <bits/stdc++.h>
using namespace std;

int ind;
string s;

int rec(){
    int sum = 0;
    for(int i=ind;i<s.size();i++){
        if(s[i] == '(' and s[i+1] == ')') sum++;
        else if(s[i] == '(' and s[i+1] == '('){
            ind = i + 1;
            sum += 2*rec();
            i = ind;
        } 
        else if(s[i] == ')' and (i == s.size()-1 or s[i+1] == ')')){
            ind = i;
            return sum;
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    cout << rec();
}