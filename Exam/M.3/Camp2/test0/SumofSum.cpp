#include <iostream>
using namespace std;

int main(){
    int x,ans=0;
    cin >> x;
    for(int i=1;i<=x;i++){
        int sum = 0;
        for(int j=1;j<=i;j++) sum += j;
        ans += sum;
    }
    cout << ans;
}