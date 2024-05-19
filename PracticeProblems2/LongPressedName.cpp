/*
Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, 
and the character will be typed 1 or more times.

You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, 
with some characters (possibly none) being long pressed.

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed output.

@Leetcode
Difficulty level : Easy

*/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int len1 = name.length();
        int len2 = typed.length();
        // std::cout<<len1<<" "<<len2<<endl;
        
        if(name == typed){
            return true;
        }
        if(typed[0] != name[0]){
            return false;
        }
        if(typed[len2-1] != name[len1-1]){
            return false;
        }
        int i=0,j=0;
        while((i < len1) && (j < len2)){
            if(name[i] == typed[j]){
                i++;
                j++;
            }
            else{
                if(typed[j] == name[i-1]){
                    j++;
                }
                else{
                    return false;
                }
            }
        }
        if((i == len1) && (j == len2)){
            return true;
        }
        else if((i == len1) && (j != len2)){
            while(j != len2){
                if(typed[j] == name[i-1]){
                    j++;
                }
                else{
                    return false;
                }
            }
            if(j == len2){
                return true;
            }
        }
        else if((i != len1) && (j == len2)){
            return false;
        }
        
        return true;
    }
};