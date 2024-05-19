/*
You are given a 0-indexed array of strings words and a character x.
Return an array of indices representing the words that contain the character x.
Note that the returned array may be in any order.

Example 1:
Input: words = ["leet","code"], x = "e"
Output: [0,1]
Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.

Example 2:
Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
Output: [0,2]
Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.

Example 3:
Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
Output: []
Explanation: "z" does not occur in any of the words. Hence, we return an empty array.

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for(int i=0; i<words.size(); i++){
            for(auto& c : words[i]) {
                if(c == x){
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<string> vect;
    vector<int> res;
    char c;
    string str;
    cout<<"Enter the strings in vector line by line:"<<endl;
    for(int i=0; i<5; ++i){
        getline(cin,str);
        vect.push_back(str);
    }
    cout<<"\nEnter the character to search: \n";
    cin>>c;

    Solution s;
    res = s.findWordsContaining(vect, c);

    for(int i=0; i<res.size(); ++i)
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}