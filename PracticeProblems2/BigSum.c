#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	long long *a;
	scanf("%d",&n);
	a = malloc(n * sizeof(long long));
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	for(i=0;i<n;++i)
	{
		long long sum = 0;
		sum  = sum + a[i];
	}
	printf("%ld",sum);
	return 0;
}