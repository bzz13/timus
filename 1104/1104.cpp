#include <stdio.h>
#include <ctype.h>
long num=0,v,max=1,k;
char ch;

int main()
{

	ch=getchar();

	do
	{
		if(isdigit(ch)) v=ch-48;
		else v=ch-55;
		num+=v;
		if(v>max) max=v;
		ch=getchar();
	}
	while(ch!='\n');


	for(k=max;k<36;k++)
		if(num%k==0)
		break;

	if(k<36)
		printf("%ld",k+1);
	else
		printf("No solution.");

	return 0;
}