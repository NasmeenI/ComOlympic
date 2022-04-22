#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x){
   return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

int prec(char c){
    if(c == '^') return 3;
    else if(c=='*' or c=='/') return 2;
    else if(c=='+' or c=='-') return 1;
    return -1;
}

string infix_postfix(string s){
    stack<char> st;
    string result;
    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(c == ' ') continue;

        if(isOperand(c)) result += c;
        else if(c == '(') st.push('(');
        else if(c == ')'){
            while(!st.empty() and st.top()!='('){
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.pop();
        }
        else{
            while(!st.empty() and prec(s[i]) <= prec(st.top())){
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        char temp = st.top();
        st.pop();
        result += temp;
    }
    return result;
}

string postfix_infix(string exp){
    stack<string> s;

    for (int i=0; exp[i]!='\0'; i++){
        if (isOperand(exp[i])){
           string op(1, exp[i]);
           s.push(op);
        }
        else{
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    return s.top();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string infix = "a+b*c+(d*e+f)*g";
    string postfix = "abc*+de*f+g*+";

    cout << infix_postfix(infix) << endl;
    cout << postfix_infix(postfix);
}
