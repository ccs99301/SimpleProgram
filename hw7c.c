#include <stdio.h>

int main()
{
	int a[1000],space=0,i=0,j,k;
	while(scanf("%d",&a[i])!=EOF)
		i++;
	for(j=0;j<i;j++)
	{
		printf("--n = %d--\n",a[j]);
		if(a[j]%2==1)
		{
			space=a[j]/2;
			while(1)
			{
				for(k=0;k<space+1;k++)
					printf(" ");
				for(k=0;k<a[j]-(space*2);k++)
					printf("*");
				for(k=0;k<space+1;k++)
					printf(" ");
				printf("\n");
				space--;
				if(space<0)
					break;
			}
			space=1;
			while(1)
			{
				for(k=0;k<space+1;k++)
					printf(" ");
				for(k=0;k<a[j]-(space*2);k++)
					printf("*");
				for(k=0;k<space+1;k++)
					printf(" ");
				printf("\n");
				space++;
				if(space>a[j]/2)
					break;
			}
		}
		else
			printf("n is not an odd number.\n");
		printf("\n");
	}
	return 0;
}
