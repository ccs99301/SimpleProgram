#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i,j,max=0;
	char text[6001][100],tmp[100];
	while(fgets(text[max],6001,stdin)!=NULL)
		max++;
	for(i=0;i<max;i++)
		for(j=0;j<max-i-1;j++)
			if(strcmp(text[j],text[j+1])>0)
			{
				strcpy(tmp,text[j]);
				strcpy(text[j],text[j+1]);
				strcpy(text[j+1],tmp);
			}
	for(i=0;i<max;i++)
		printf("%s",text[i]);
	return 0;
}
