#include <bits/stdc++.h>
#define N 1000010
using namespace std;

int n ,ans ,arr[N];
vector<int> dp(N ,1);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1;i<=n;i++) cin >> arr[i];

	for(int i=1;i<=n;i++){
	    for(int j=1;j<i;j++){
	        if(arr[j] >= arr[i]) continue;
	        dp[i] = max(dp[i] ,dp[j]+1);
	        ans = max(ans ,dp[i]);
	    }
	}
	cout << ans;
}