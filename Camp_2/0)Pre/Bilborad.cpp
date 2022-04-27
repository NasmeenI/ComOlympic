#include <iostream>
using namespace std;

int main(){
	int n,max=0;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	
	for(int i=0;i<n;i++){
		int c = 0;
		if(arr[i] > 0) c++;
		for(int j=i+1;j<n;j++){
			if(arr[j] >= arr[i]) c++;
			else break;
		}
		for(int j=i-1;j>0;j--){
			if(arr[j] >= arr[i]) c++;
			else break;
		}
		if(max < arr[i]*c) max = arr[i]*c;
	}
	cout << max;
}
/*
9
1 3 0 0 5 0 4 3 1

5
2 3 3 6 1

10
10 3 2 0 5 0 4 3 1 1

7
5 0 8 0 3 6 4
*/
