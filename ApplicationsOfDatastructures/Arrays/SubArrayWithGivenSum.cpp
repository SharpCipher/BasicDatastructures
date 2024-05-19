//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> res;
        int startIndex = 0;
        long long currSum = arr[0];
        if(currSum == s) {
            res.push_back(startIndex+1);
            res.push_back(startIndex+1);
        }
        for(int i=1; i<n; i++){
            currSum += arr[i];  // currSum already has first element
            if(currSum == s){
                res.push_back(startIndex+1);
                res.push_back(i+1);
                break;
            }
            else if(currSum > s) {
                bool flag = false;
                while(startIndex < i && currSum > s) {
                    currSum -= arr[startIndex++]; //shrinking the range
                    if(currSum == s) {
                        res.push_back(startIndex+1);
                        res.push_back(i+1);
                        flag = true;
                        break;      // break from while
                    }
                }
                if(flag == true)  // We got the required indices
                    break;        // so break from for
            }
        }
        if(res.size() == 0)
            return {-1};
        return res;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends