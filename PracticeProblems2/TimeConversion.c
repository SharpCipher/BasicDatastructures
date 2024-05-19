#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{	
	int hh,mm,ss;
	char k[3];
	scanf("%d:%d:%d%s",&hh,&mm,&ss,k);
	if(strcmp(k,"PM") == 0 && hh != 12)
		hh += 12;
	if(strcmp(k,"AM") == 0 && hh == 12)
		hh = 0;

	printf("%d:%d:%d",hh,mm,ss);
	return 0;
}