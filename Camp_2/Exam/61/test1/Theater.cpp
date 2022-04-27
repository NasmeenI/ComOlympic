#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r,s,c;
    cin >> r >> s >> c;
    string arr[r];
    for(int i=0;i<r;i++) cin >> arr[i];

    for(int i=0;i<r;i++){
        for(int j=0;j<8;j++){
            if(c>0 and arr[i][j]=='0' and arr[i][j+1]=='0' and (j-1<0 or arr[i][j-1]=='0') and (j+2>8 or arr[i][j+2]=='0') and (i-1<0 or (arr[i-1][j]=='0' and arr[i-1][j+1]=='0'))){
                arr[i][j] = '1';
                arr[i][j+1] = '1';
                c--;
            }
            else if(s>0 and arr[i][j]=='0' and (j-1<0 or arr[i][j-1]=='0') and (j+2>8 or arr[i][j+1]=='0') and (i-1<0 or arr[i-1][j]=='0')){
                arr[i][j] = '1';
                s--;
            }
        }
    }
    if(s>0 or c>0) cout << "no";
    else cout << "yes";
}