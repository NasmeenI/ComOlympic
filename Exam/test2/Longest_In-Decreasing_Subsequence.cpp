//Longest IN-Decreasing Subsequence Camp2/test2 2564
#include <bits/stdc++.h>
#define N 1000010
using namespace std;

int n,mx1,mx2,mx3;
vector<int> arr(N) ,dp_increase(N ,1) ,dp_decrease(N ,1) ,dp_in_de(N);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    
    //find dp_incress
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[i] <= arr[j]) continue;
            dp_increase[i] = max(dp_increase[i] ,dp_increase[j]+1);
        }
        mx1 = max(mx1 ,dp_increase[i]);
    }

    //find dp_reduce
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[i] >= arr[j]) continue;
            dp_decrease[i] = max(dp_decrease[i] ,dp_decrease[j]+1);
        }
        mx2 = max(mx2 ,dp_decrease[i]);
    }

    //find dp_in_de
    dp_in_de = dp_increase;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[i] >= arr[j]) continue;
            dp_in_de[i] = max(dp_in_de[i] ,dp_in_de[j]+1);
        }
        mx3 = max(mx3 ,dp_in_de[i]);
    }
    cout << max(mx1 ,max(mx2 ,mx3));
}
/*
9
14 12 15 19 17 16 20 13 11

5
1 9 3 4 5

5
5 4 3 9 1
*/