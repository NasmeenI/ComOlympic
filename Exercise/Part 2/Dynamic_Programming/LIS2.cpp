#include <bits/stdc++.h>
#define N 1010
using namespace std;

int n ,p ,ans ,arr[N];
vector<int> dp(N ,1);
vector<vector<int>> v(N);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1;i<=n;i++) cin >> arr[i];

	for(int i=1;i<=n;i++){
	    for(int j=1;j<i;j++){
	        if(arr[j] >= arr[i]) continue;
	        if(dp[i] < dp[j]+1){
	            dp[i] = dp[j]+1;
	            v[i] = v[j];
	        }

	        if(ans < dp[i]){
	            ans = dp[i];
	            p = i;
	        }
	    }
	    v[i].push_back(arr[i]);
	}
	cout << ans << endl;
	for(int i=0;i<v[p].size();i++) cout << v[p][i] << ' ';
}
