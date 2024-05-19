/*
    You are choreographing a circus show with various animals. 
    For one act, you are given two kangaroos on a number line ready to jump in the positive direction 
    (i.e, toward positive infinity).

    The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
    The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.

You have to figure out a way to get both kangaroos at the same location at the same time as part of the show. 
If it is possible, return YES, otherwise return NO. 

EXAMPLE:

x1=2, v1=1, x2=1, v2=2

After one jump, they are both at x = 3 (x1+v1=2+1, x2+v2=1+2), so the answer is YES.

*/

#include<iostream>
#include<bits/stdc++.h>
int main()
{
	int x1,v1,x2,v2;
	int f = 0;
	scanf("%d%d%d%d",&x1,&v1,&x2,&v2);
	if(v2>=v1 && x1!=x2){
       
       printf("NO");
       
   }
   else{
       
       float x = (float)(x2-x1)/(v1-v2);

       if( floor(x) == x )
           printf("YES");
       else
           printf("NO");
       
   }
	return 0;
}

