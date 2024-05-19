#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,c_b,c_w;
	int best,worst;
	c_w = c_b = 0;
	int *a;
	scanf("%d",&n);
	a = malloc(n * sizeof(int));
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	best = a[0];
	for(i=0;i<n;++i)
	{
		if(a[i] > best)
		{
			best = a[i];
			++c_b;
		}
	}
	worst = a[0];
	for(i=0;i<n;++i)
	{
		if(a[i] < worst)
		{
			worst = a[i];
			++c_w;
		}
	}
	printf("%d %d",c_b,c_w);
	return 0;
}