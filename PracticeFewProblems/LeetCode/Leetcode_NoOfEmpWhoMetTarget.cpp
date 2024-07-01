/*
There are n employees in a company, numbered from 0 to n - 1. Each employee i has worked for hours[i] hours in the company.
The company requires each employee to work for at least target hours.
You are given a 0-indexed array of non-negative integers hours of length n and a non-negative integer target.
Return the integer denoting the number of employees who worked at least target hours.
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int c = 0;
        int sz = hours.size();
        //sort(hours.begin(), hours.end());
        for(int i=0; i<sz; ++i){
            if(hours[i] >= target){
                c++;
            }
        }
        return c;
    }
};

int main() {
    vector<int> input(5,0);
    int t;
    cout<<"Enter the working hours: \n";
    for(int i=0; i<5; i++){
        cin>>input[i];
    }
    cout<<"Enter the target: ";
    cin>>t;
    Solution obj;
    cout<<"Number of people who met the target: \n";
    cout << obj.numberOfEmployeesWhoMetTarget(input, t) << '\n';

    return 0;
}