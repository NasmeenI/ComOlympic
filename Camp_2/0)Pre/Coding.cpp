#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int arr[n][m] ,a[n];
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=0;j<m;j++){
			cin >> arr[i][j];
			sum += arr[i][j];
		}
		a[i] = sum%26;
	}
	for(int i=0;i<n;i++) printf("%c",a[i]+96);	
}
/*
5 4
2 3 1 2
1 24 1 1
9 1 4 2
9 1 4 2
5 10 5 5

5 3
2 3 1
7 9 5
7 0 7
14 0 0
10 5 10
*/
