#include<stdio.h>
#include<stdlib.h>
int k1, flag = 0;
int main()
{
	int *p;
	int n,i,j;
	printf("Enter total no.of Elements:\n");
	scanf("%d",&n);
	printf("Enter Elements:\n");
	for(i=0;i<n-1;++i)
	{
		scanf("%d",&p[i]);
	
	}
	
	for(i=0;i<n;++i)
	{
		if((p[i+1] - p[i]) != 1)
		{
			k1 = p[i];
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	printf("Missed Element:%d\n",k1 + 1);
	return 0;
}
