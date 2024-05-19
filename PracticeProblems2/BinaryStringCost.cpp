/*
According to the new tax scheme, a new tax called the binary string tax was introduced! JJ has a binary string S of length N. 
According to the tax scheme, for every occurrence of 01 in S, a tax of X rupees will be charged, 
while for every occurrence of 10 in S, a tax of Y rupees will be charged.

For example, if X=5, Y=7 and S=11010, then S has 1 occurrence of 01 and 2 occurrences of 10, so the tax charged =5⋅1+7⋅2=19

JJ can rearrange the string S in any way he wants. He wants to minimize the amount of tax he has to pay. 
Can you help him do so?

2
4 7 3
1101
5 3 4
00000

Output:
3
0

@Codechef - My First Contest
*/

//#include <iostream>
//#include<string>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,x,y;
	    cin>>n>>x>>y;
	    string s;
	    cin>>s;
	    int c1=0, c2=0;
	    for(int i=0; i<n; i++){
	        if(s[i] == '1')
	            c1++;
	        if(s[i] == '0')
	            c2++;
	    }
	    if(x > y){
	        sort(s.begin(),s.end(), greater<int>());
	        if(c1>0 && c2>0)
	            cout<<y<<endl;
	       else
	            cout<<"0"<<endl;
	    }
	    else{
	        sort(s.begin(),s.end());
	        if(c1>0 && c2>0)
	            cout<<x<<endl;
	        else
	            cout<<"0"<<endl;
	    }
	}
	return 0;
}
