/*
Chef decided to go on a diet during the following N days (numbered 1 through N). Part of the diet plan is to eat K grams of protein during each day. 
For each valid i, Chef wants to buy Ai grams of protein in the morning of the i-th day and then eat K grams of protein as part of his dinner. 
If he has any protein remaining, he can store it and use it in later dinners. Initially, Chef is storing 0 grams of protein.

Determine whether Chef will have enough protein all the time during his diet. In case he will not have enough, 
find the first day on which Chef will be unable to eat K grams of protein.

Input:
3
4 5
7 3 6 5
3 4
3 10 10
3 4
8 1 1

Output:
YES
NO 1
NO 3
*/
/*@Codechef*/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    int rem,t;
	    int i;
	    for(i=0; i<n; i++){
	        if(arr[i] < k){
	            cout<<"NO"<<" "<<i+1<<endl;
	            break;
	        }
	        else{
	            rem = arr[i]-k;
	            t = arr[i+1];
	            arr[i+1] = t+rem;
	        }
	        if(i == n-1){
	            cout<<"YES"<<endl;
	            break;
	        }
	    }
	    
	}
	return 0;
}
