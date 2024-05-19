#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n,i,j;
	int sum1,sum2,k1,k2,k3;
	sum1 = sum2 = 0;
	scanf("%d",&n);
	int arr[n][n];
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(i == j)
			{
				sum1 = sum1 + arr[i][j];
			}
		}
	}
	
	for(i=0,j=n-1;i<n,j>=0;++i,--j)
	{

			sum2 = sum2 + arr[i][j];
	}
	printf("%d\n",abs(sum1 - sum2));
	return 0;
}