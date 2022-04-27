#include <bits/stdc++.h>
using namespace std;

struct data{
    string s;
    int a;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    data temp;
    vector<data> v;
    string ins;
    getline(cin,ins);
    for(int i=0;i<ins.size();i++){
        if(ins[i]>=48 and ins[i]<=57){
            temp.s = ins[i];
            temp.a = 0;
            v.push_back(temp);
        }
        else{
            if(ins[i] == '+'){
                string s1 = v[v.size()-2].s+" + "+v[v.size()-1].s;
                v.pop_back();
                v.pop_back();
                temp.s = s1;
                temp.a = 1;
                v.push_back(temp);
            }
            else if(ins[i] == '-'){
                string s1 = v[v.size()-2].s+" - "+v[v.size()-1].s;
                v.pop_back();
                v.pop_back();
                temp.s = s1;
                temp.a = 1;
                v.push_back(temp);
            }
            else if(ins[i] == '*'){
                string s1,s2;
                if(v[v.size()-2].a == 1) s1 = "( "+v[v.size()-2].s+" )";
                else s1 = v[v.size()-2].s;
                if(v[v.size()-1].a == 1) s2 = "( "+v[v.size()-1].s+" )";
                else s2 = v[v.size()-1].s;
                
                string s3 = s1+" * "+s2;
                v.pop_back();
                v.pop_back();
                temp.s = s3;
                temp.a = 2;
                v.push_back(temp);
            }
            else if(ins[i] == '/'){
                string s1,s2;
                if(v[v.size()-2].a == 1) s1 = "( "+v[v.size()-2].s+" )";
                else s1 = v[v.size()-2].s;
                if(v[v.size()-1].a == 1) s2  ="( "+v[v.size()-1].s+" )";
                else s2 = v[v.size()-1].s;
                string s3 = s1+" / "+s2;
                v.pop_back();
                v.pop_back();
                temp.s = s3;
                temp.a = 2;
                v.push_back(temp);
            }
        }
    }

    stack<int> st;
    string s = v[0].s;
    cout << s << endl;

    for(int i=0;i<ins.size();i++){
        if(ins[i]>=48 and ins[i]<=57){
            st.push(ins[i]-'0');
        }
        else if(ins[i]==' ' or ins[i]=='(' or ins[i]==')'){
        }
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(ins[i] == '+') st.push(a+b);
            else if(ins[i] == '-') st.push(b-a);
            else if(ins[i] == '*') st.push(b*a);
            else if(ins[i] == '/') st.push(b/a);
        }
    }
    cout << st.top();
}
/*
5 7 + 2 3 + *
5 7 2 * + 3 +
*/
