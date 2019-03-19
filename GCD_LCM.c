#include <stdio.h>

int GCD(int x,int y)
{
	int z=x;
	while(1)
	{
		if(x%z==0&&y%z==0)
			break;
		z--;
	}
	return z;
}
int LCM(int x,int y)
{
	int z=x;
	while(1)
	{
		if(z%x==0&&z%y==0)
			break;
		z++;
	}
	return z;
}
int main()
{
	int a[1000],b[1000],i=0,j;
	while(scanf("%d%d",&a[i],&b[i])!=EOF)
		i++;
	for(j=0;j<i;j++)
	{
		printf("--%d,%d--\n",a[j],b[j]);
		printf("GCD = %d\n",GCD(a[j],b[j]));
		printf("LCM = %d\n",LCM(a[j],b[j]));
		printf("\n");
	}
	return 0;
}
