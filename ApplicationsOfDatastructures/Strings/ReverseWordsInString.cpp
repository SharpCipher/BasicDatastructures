/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        int len = s.length();
        string s2;
        int r;
        for(int i=len-1; i>=0; --i){
            if(s[i] == '.'){
                r = len - i;
                len = i - 1;
                s2.append(s.substr(i+1, r));
                s2.append(".");
            }
        }
        s2.append(s.substr(0,len+1));
        return s2;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends