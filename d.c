#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int value[1000],i=0,max=0;
	char dic[1000][100],*ptr,pat[100];
	FILE *fpd,*fpp;
	fpd=fopen(argv[1],"r");
	fpp=fopen(argv[2],"r");
	while(fgets(dic[max],1000,fpd)!=NULL)
	{
		ptr=strchr(dic[max],' ');
		value[max]=atoi(ptr);
		*ptr='\0';
		max++;
	}
	while(fgets(pat,1000,fpp)!=NULL)
	{
		ptr=strchr(pat,'\n');
		*ptr='\0';
		ptr=pat;
		if(strcmp(pat,"PRINT")==0)
		{
			for(i=max-1;i>=0;i--)
				if(dic[i][0]!='\0')
					printf("%s %d\n",dic[i],value[i]);
		}
		else if(*ptr=='-')
		{
			ptr++;
			for(i=0;i<max;i++)
				if(strcmp(ptr,dic[i])==0)
				{
					printf("%s DELETED\n",dic[i]);
					dic[i][0]='\0';
					break;
				}
			if(i==max)
				printf("%s NOT_FOUND\n",ptr);
		}
		else
		{
			for(i=0;i<max;i++)
				if(strcmp(pat,dic[i])==0)
				{
					printf("%s %d\n",dic[i],value[i]);
					break;
				}
			if(i==max)
				printf("%s NOT_FOUND\n",pat);
		}
	}
	return 0;
}
