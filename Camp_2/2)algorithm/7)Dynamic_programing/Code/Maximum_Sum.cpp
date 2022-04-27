#include <bits/stdc++.h>
#define N 5050
using namespace std;

int n ,ans ,arr[N] ,dp[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1;i<=n;i++) cin >> arr[i];
	for(int i=1;i<=n;i++){
	    dp[i] = max(arr[i] ,dp[i-1]+arr[i]);
	    ans = max(ans,dp[i]);
	}
	cout << ans;
}
