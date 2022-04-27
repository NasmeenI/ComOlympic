#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

void merge(int l ,int r ,int mid){
	vector<int> v1 = v;
	int i=l ,j=mid+1 ,k=l;
	while(i<=mid && j<=r){
		if(v[i] < v[j]) v1[k++] = v[i++];
		else  v1[k++] = v[j++];
	}
	while(i <= mid) v1[k++] = v[i++];
	while(j <= r) v1[k++] = v[j++];
	for(int i=0;i<v.size();i++) v[i] = v1[i];
}

void mergesort(int l ,int r){
	if(l == r) return ;
	int mid=(low+high)/2;
	mergesort(l ,mid);
	mergesort(mid+1 ,r);
	merge(l ,r ,mid);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	mergesort(0 ,v.size()-1);
	for(int i=0;i<n;i++) cout << v[i] << ' ';
}

