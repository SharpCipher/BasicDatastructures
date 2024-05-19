/*
You are given an integer N and the task is to reverse the digits of the given integer.
Return 0 if the result overflows and does not fit in a 32 bit signed integer
Example Input

Input 1:

 x = 123

Input 2:

 x = -123

Example Output

Output 1:

 321

Ouput 2:

 -321

 @InterviewBit

*/

int Solution::reverse(int A) {
    int s=1,rem, d=0;

    if(A<0)
        s=-1;
    A *= s;
    while(A>0){
        rem = A%10;
        if(d >INT_MAX/10 -rem)
            return 0;
        d = d*10+rem;
        A = A/10;
    }
    return d*s;
}
