#include <stdio.h>

int main()
{
	int k;
	while(1)
	{
		printf("input:");
		scanf("%d",&k);
		if(k==0)
		{
			printf("end!\n");
			return 0;
		}
		else
		{
			float n=k*30.48;
			printf("output:%f\n",n);
		}
	}
	return 0;
}
