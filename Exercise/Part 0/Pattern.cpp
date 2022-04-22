#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	char arr[n+1][70+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=70;j++){
			arr[i][j] = 'o';
		}
	}
	for(int k=0;k<n;k++){
		int a,b,c;
		cin >> a >> b >> c;
		for(int j=b;j<b+c;j++) arr[a][j] = 'x';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=70;j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
}
/*
5
3 2 5
1 10 2
1 13 5
5 1 2
5 3 1
*/
