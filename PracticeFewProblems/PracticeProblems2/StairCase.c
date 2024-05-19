#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(j<(n-1-i))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
	return 0;
}
