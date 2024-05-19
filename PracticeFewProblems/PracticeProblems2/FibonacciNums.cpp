#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	long long res;
	cin>>n;

	vector<long long> v(n);

	v[0] = 0;
	v[1] = 1;

	for(int i=2; i<=n; i++){
		v[i] = v[i-1] + v[i-2];
		res = v[i];
	}
	cout<<res<<endl;

	return 0;
}
