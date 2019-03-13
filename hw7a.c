#include <stdio.h>

int isPrime(int x)
{
	int state,y=1;
	while(1)
	{
		y++;
		if(y==x)
		{
			state=0;
			break;
		}
		if(x%y==0)
		{
			state=1;
			break;
		}
	}
	return state;
}
void sort(int data[],int let)
{
	int i,th=0,tmp;
	for(i=0;i<let;i++)
	{
		while(i+th<let)
		{
			th++;
			if(data[i]>data[i+th])
			{
				tmp=data[i];
				data[i]=data[i+th];
				data[i+th]=tmp;
			}
		}
		th=0;
	}
}
int main()
{
	int a[1000],i,j;
	while(scanf("%d",&a[i])!=EOF)
		i++;
	printf("--isPrime--\n");
	for(j=0;j<i;j++)
	{
		printf("%d:",a[j]);
		if(isPrime(a[j])==0)
			printf(" yes\n");
		else
			printf(" no\n");
	}
	printf("\n--Sort--\n");
	sort(a,i-1);
	for(j=0;j<i;j++)
		printf("%d\n",a[j]);
	return 0;
}
