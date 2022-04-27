#include <bits/stdc++.h>
using namespace std;

int key,n;
vector<int> v;

int binary_search(int l ,int r){
	if(l == r) return -1;

    int mid=(l+r)/2;
    if(key==v[mid]) return mid;

    if(key > v[mid]) binary_search(mid+1 ,r);
    else binary_search(l ,mid-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin >> key >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	cout << binary_search(0 ,v.size()-1);
}
