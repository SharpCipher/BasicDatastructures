/*
You are in charge of the cake for a child's birthday. 
You have decided the cake will have one candle for each year of their total age. 
They will only be able to blow out the tallest of the candles. Count how many candles are tallest. 

Example

candles = [4,4,1,3]

The maximum height candles are 4 units high. There are 2 of them, so return 2.

birthdayCakeCandles has the following parameter(s):

    int candles[n]: the candle heights

Returns

    int: the number of candles that are tallest

*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,max;
	int *a;
	int count = 0;
	scanf("%d",&n);
	a = (int *)malloc(n * sizeof(int));
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	max = a[0];
	for(i=0;i<n;++i)
	{
		if(a[i] > max)
			max = a[i];

	}
	for(i=0;i<n;++i)
	{
		if(a[i] == max)
			++count;
	}
	printf("%d\n",count);
	return 0;
}

