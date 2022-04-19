//Parentheses Camp2/test1 2564
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> st;
    int ans1=0,ans2=0,ans3=0;
    bool ck = true;
    for(auto e:s){
        if(e == '(' or e == '[' or e == '{') st.push(e);
        else{
            if(e == ')'){
                if(st.top() == '('){
                    ans1++;
                    st.pop();
                }
                else{
                    ck = false;
                    break;
                }
            }
            else if(e == ']'){
                if(st.top() == '['){
                    ans2++;
                    st.pop();
                }
                else{
                    ck = false;
                    break;
                }
            }
            else if(e == '}'){
                if(st.top() == '{'){
                    ans3++;
                    st.pop();
                }
                else{
                    ck = false;
                    break;
                }
            }
        }
    }
    if(!ck) cout << "No";
    else cout << ans1 << '\n' << ans2 << '\n' << ans3;
}
/*
([[}})
([{}]{{}[]})
*/