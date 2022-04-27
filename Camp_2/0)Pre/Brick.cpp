#include <bits/stdc++.h>
#define N 20
#define INF 1e9
using namespace std;

int n,m;
vector<int> mn(N ,INF) ,brick(N);
vector<vector<char>> arr(N ,vector<char> (N));

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> arr[i][j];
			if(arr[i][j] == 'O') mn[j] = min(mn[j] ,i);
			if(i+1 == n and mn[j] > i) mn[j] = i+1;
		}
	}
	for(int j=0;j<m;j++) cin >> brick[j];
	for(int j=0;j<m;j++){
        while(brick[j]-- and mn[j] > 0){
            arr[--mn[j]][j] = '#';
        }
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
}
