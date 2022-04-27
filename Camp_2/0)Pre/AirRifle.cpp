#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ll n;
	cin >> n;
	int ablack[n] ,awhile[n] ,agray[n];
	for(int i=0;i<n;i++) cin >> ablack[i];
	for(int i=0;i<n;i++) cin >> agray[i];
	for(int i=0;i<n;i++) cin >> awhile[i];
	
	ll m,max=0;
	cin >> m;
	int gun[m];
	for(int i=0;i<m;i++){
		cin >> gun[i];
		if(gun[i] > max) max = gun[i];
	}
	max += m;
	vector<int> v[n] ,v2;
	for(int i=0;i<n;i++){
		while(ablack[i] != 0){
			v[i].push_back(1);
			ablack[i]--;
		}
		while(agray[i] != 0){
			v[i].push_back(2);
			agray[i]--;
		}
		while(awhile[i] != 0){
			v[i].push_back(5);
			awhile[i]--;
		}
	}
	for(int i=0;i<n;i++){
		int sizev = v[i].size();
		if(sizev <= max){
			for(int j=1;j<=max-sizev;j++) v[i].push_back(0);
		}
	}
	for(int k=0;k<m;k++){
		int sum = 0;		
		for(int i=0;i<n;i++){
			sum += v[i][gun[k]-1];
			v[i].erase(v[i].begin()+gun[k]-1);
		} 
		v2.push_back(sum);
	}
	for(int i=0;i<v2.size();i++) cout << v2[i] << endl;
}
/*
6
2 1 2 0 3 1 
1 2 2 2 2 0
1 0 1 2 0 3
2
2 4

10
2 2 2 2 2 2 2 2 2 2
3 3 3 3 3 3 3 3 3 3
4 4 4 4 4 4 4 4 4 4
6
3 3 2 3 4 3
*/
