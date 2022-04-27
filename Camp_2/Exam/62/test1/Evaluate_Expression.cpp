#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin ,s);
    float a,b;
    cin >> a >> b;

    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            s.erase(s.begin()+i);
            i--;
        }
    }
    vector<float> v;
    for(int i=0;i<s.size();i++){
        if(s[i] >= '0' and s[i] <= '9') v.push_back(s[i] - '0');
        else if(s[i] == 'x') v.push_back(a);
        else if(s[i] == 'y') v.push_back(b); 
        else if(s[i] == '+') v.push_back(-123456);
        else if(s[i] == '-') v.push_back(-234567);
        else if(s[i] == '*') v.push_back(-345678);
        else if(s[i] == '/') v.push_back(-456789);
    }

    for(int i=0;i<v.size();i++){
        if(v[i] == -345678 or v[i] == -456789){
            float x;
            if(v[i] == -345678) x = v[i-1] * v[i+1];
            else x = v[i-1] / v[i+1];
            v[i-1] = x;
            v.erase(v.begin()+i);
            v.erase(v.begin()+i);
            i--;
        }
    }

    for(int i=0;i<v.size();i++){
        if(v[i] == -123456 or v[i] == -234567){
            float x;
            if(v[i] == -123456) x = v[i-1] + v[i+1];
            else x = v[i-1] - v[i+1];
            v[i-1] = x;
            v.erase(v.begin()+i);
            v.erase(v.begin()+i);
            i--;
        }
    }
    cout << v[0];
}