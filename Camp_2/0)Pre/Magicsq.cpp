#include <iostream>
using namespace std;

int main(){
	int n,c=0;
	cin >> n;
	int arr[n][n],sum1[n],sum2[n],sum3=0,sum4=0;
	for(int i=0;i<n;i++) sum1[i] = 0;
	for(int i=0;i<n;i++) sum2[i] = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
			sum1[i] += arr[i][j];
			sum2[j] += arr[i][j];
			if(i == j) sum3 += arr[i][j];
			if(i+j == n-1) sum4 += arr[i][j];
		}
	}
	int sum = sum1[0];
	for(int i=0;i<n;i++){
		if(sum1[i] == sum) c++;
		if(sum2[i] == sum) c++;
	}
	if(sum3 == sum) c++;
	if(sum4 == sum) c++;
	if(c == n+n+2) cout << "Yes";
	else cout << "No";
}
/*
4
16 2 3 13
5 11 10 8
9 7 6 12
4 14 15 1

3
16 2 3
5 11 10
9 7 6
*/
