#include<stdio.h>
#include <stdlib.h>
int main()
{
	int p[50],l[20];
	int i,n,j=0;
	printf("Enter no.of Elements:\n");
	scanf("%d",&n);
	printf("Enter %d elements of an Array\n",n);
	for(i=0;i<n;++i)
		scanf("%d",&p[i]);
	for (i = n-1; i > 0; --i)
	{
		if(p[i] < p[i-1])
			l[j++] = p[i-1];
		else
			l[j++] = p[i];
	}
	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("%s\n", );
	}
	return 0;
}