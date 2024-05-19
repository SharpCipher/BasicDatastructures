/*
Problem Note

The input contains only the characters 'I', 'V', 'X', 'L', 'C', 'D', 'M'.
Input is a valid roman numeral in the range [1, 3999].
A number in Roman numerals is a string of these symbols written in descending order i.e. largest to 
smallest from left to right. For example, 2 is written as II in Roman numeral, just two ones added together.
12 is written as XII, which is simply X + II. The number 27 is XXVII, which is XX + V + II.
We avoid four characters being repeated in successions such as IIII or VIIII. Instead, the number four
is written as IV because the 1 is before the 5, and we subtract it making 4. The same principle applies to number 9,
which is written as IX. The idea is: when there is a smaller number placed before a larger number, the values are 
subtracted.

Example 1: Input: XL, Output: 40
Explanation: XL is a Roman symbol which represents 40

Example 2: Input: MCMIV, Output: 1904
Explanation: M = 1000, CM = 900, IV = 4

Example 3: Input: LVIII, Output: 58
Explanation: L = 50, V= 5, III = 3

Example 4: Input: MCMXCIV, Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4

*/
#include <iostream>

int integerValues(char c) {
    if(c == 'I'){
        return 1;
    }
    if(c == 'V') {
        return 5;
    }
    if(c == 'X') {
        return 10;
    }
    if(c == 'L') {
        return 50;
    }
    if(c == 'C') {
        return 100;
    }
    if(c == 'D') {
        return 500;
    }
    if (c == 'M'){
        return 1000;
    }
    return -1;
}

int romanToIntegerConvApproach1(const std::string& roman, const int n) {
    int Result = 0;
    for(int i=0; i<n; ++i) {
        int current = integerValues(roman[i]);
        if(i+1 < n) {
            int next = integerValues(roman[i+1]);
            /*
            Case 1: The string of symbols will appear in descending order or three characters being
            repeated in successions.
            */
            if(current >= next) {  
                Result += current;
            }
            /*
            Case 2: The smaller Roman number is placed before a larger number or four characters is not 
            repeated in the successions.
            */
            else {
                /*
                (next - current) is the combined integer value of the two roman characters,
                so we also increment the value of i by 1. 
                Also note that we are also incrementing i in the loop.
                */
                Result = Result + next - current;
                i += 1;
            }
        }
        /*
        Boundary condition: before calculating the value of next, we need to check: do we present at the last index?
        If yes, then there is no need to calculate next and we just add the curr to the output
        i.e. Result = Result + currrent.
        */
        else {
            Result += current;
        }
    }
    return Result;
}

int romanToIntegerConvApproach2(const std::string& roman, const int n) {
    int Result = 0;
    for(int i=0; i<n; ++i) {
        int current = integerValues(roman[i]);
        if(i+1 < n) {
            int next = integerValues(roman[i+1]);
            if(current >= next) {
                Result += current;
            }
            else {
                Result -= current;
            }
        }
        else {
            Result += current;
        }
    }
    return Result;
}

int main() {
    std::string roman;
    std::cout << "Enter the Roman string: ";
    std::getline(std::cin, roman);
    int n = roman.size();
    std::cout << "Approach1: \n";
    std::cout << "Integer equivalent to the entered Roman string: " << romanToIntegerConvApproach1(roman, n) << '\n';
    std::cout << "Approach2: \n";
    std::cout << "Integer equivalent to the entered Roman string: " << romanToIntegerConvApproach2(roman, n) << '\n';

    return 0;
}