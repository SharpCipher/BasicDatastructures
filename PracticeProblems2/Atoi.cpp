/*
Your task  is to implement the function atoi. 
The function takes a string(str) as argument and converts it to an integer and returns it.

Example 1:

Input:
str = 123
Output: 123

Example 2:

Input:
str = 21a
Output: -1
Explanation: Output is -1 as all
characters are not digit only.

@GeeksForGeeks
*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int res=0;
        int i=0;
        int s = 1;
        if(str[i] == '-'){
            s = -1;
            i++;
        }
        while(str[i]){
            if(!(str[i]-'0' >= 0  && str[i]-'0' <= 9))
                return -1;
            res = res*10 + str[i]-'0';
            i++;
        }
        return res*s;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends