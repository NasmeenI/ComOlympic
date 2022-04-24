#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[4] ,arr1[4];
    for(int i=0;i<4;i++) cin >> arr[i];
    for(int i=0;i<4;i++) cin >> arr1[i];

    bool ck = true;
    for(int i=0;i<4;i++){
        char x;
        int y;
        cin >> x >> y;
        if(x == 'F'){
            arr[i] = (arr[i] + y)%6;
            if(arr[i] == 0) arr[i] = 6;
        }
        else{
            if(y < arr[i]) arr[i] -= y;
            else arr[i] = 6 - (y-arr[i])%6;
        }

        cout << arr[i] << ' ';
        if(arr[i] != arr1[i]) ck = false;
    }
    cout << (ck ? "O" : "N");
}