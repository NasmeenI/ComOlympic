#include <bits/stdc++.h>
#define N 5050
using namespace std;

int n ,t ,m ,a;
vector<int> v(1,0);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;
	for(int i=1;i<=n;i++){
		cin >> a;
	    v.push_back(a);
	    v[i] = a + v[i-1];
	}
	while(t--){
	    cin >> m;
	    cout << upper_bound(v.begin() ,v.end() ,m) - v.begin() - 1 << endl;
	}
}
