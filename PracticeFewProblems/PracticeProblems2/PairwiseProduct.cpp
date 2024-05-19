#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
	bool check(const vector<int64_t>& array, int n)
	{   
    	const int a0 = array[0];

    	for (int i = 1; i < n; i++)      
    	{         
        	if (array[i] != a0)
            return true;
    	}
    	return false;
	}


	int64_t PairwiseProduct(const vector<int64_t>& arr){

		int64_t maxProduct = 0;
		int n = arr.size();
		if(n < 2){
			return 0;
		}

		bool flag = check(arr, n);

		if(flag == false){
			return arr[0]*arr[0];
		}

		int64_t max1 = arr[0];
		for(int i=0; i<n; i++){
			if(max1 < arr[i]){
				max1 = arr[i];
			}
		}
		cout<<max1<<endl;
		for(int i=0; i<n; i++){
			/*if(arr[i] != max1){
				
			}*/
			maxProduct = max(maxProduct, arr[i] * max1);
		}
		
		
	}


int main(){

	int n;
	cin>>n;
	vector<int64_t> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<PairwiseProduct(arr);

	return 0;
}
