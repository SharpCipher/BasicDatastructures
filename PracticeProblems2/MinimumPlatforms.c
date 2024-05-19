#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,p,i;
	printf("Enter the number of Trains:\n");
	scanf("%d",&n);
	p=0;
	int arr[n],dep[n];
	printf("Enter the Arriva Times of %d Trains:\n",n);
	for(int i=0;i<n;++i)
		scanf("%d",&arr[i]);
	printf("Enter the Depature Times of %d Trains:\n",n);
	for(i=0;i<n;++i)
		scanf("%d",&dep[i]);
	for(i=0;i<n-1;i++)
	{
		if(dep[i]>arr[i+1])
		++p;
	}
	printf("\nMinimum No.of Platforms Required: %d\n",p+1);
	
	return 0;
}
//900 915 1015 1045 1120 1200
//910 1020 1030 1100 1215 1245

//800 830 915 945
//835 920 950 1000
