#include <bits/stdc++.h>
#define N 10010
#define K 12
#define INF 1e9
using namespace std;

int n ,k ,coin[K];
vector<int> dp(N ,INF);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	dp[0] = 0;
	cin >> n >> k;
	for(int i=0;i<k;i++) cin >> coin[i];
 	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			if(coin[j] > i) continue;
			dp[i] = min(dp[i] ,dp[i-coin[j]]+1);
		}
	}
	cout << dp[n];
}
