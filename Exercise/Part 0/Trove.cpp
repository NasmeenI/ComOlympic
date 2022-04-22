#include <iostream>
using namespace std;

int main(){
	int n,c=0;
	cin >> n;
	int arr[n][n];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> arr[i][j];
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i][j] == arr[j][i]) c++;
		}
	}
	if(c == ((n*n)-n)/2) cout << "Yes";
	else cout << "No";
}
/*
5
10 16 3 2 13
6 5 10 11 8
9 9 6 7 12
14 4 15 14 1
5 10 11 5 6

5
16 3 5 2 16
3 10 12 10 8
5 12 10 14 5
2 10 14 15 1
16 8 5 1 4
*/
