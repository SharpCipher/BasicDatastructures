#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	int *p;
	scanf("%d",&n);
	p = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;++i)
		scanf("%d",&p[i]);
	int Msum=0;
	int sum=0;
	for(i=0;i<n;++i)
	{
		sum = sum + p[i];
		if(p[i] < 0)
			sum = 0;
		else
		{
			if(Msum < sum)
				Msum = sum;
		}

	}
	printf("MaxSumofSubArray: %d\n",Msum);
	return 0;
}
