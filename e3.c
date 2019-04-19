#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i=0,j=0,max=0,count[500],tmp=0;
	char word[500][1000],temp[1000],*ptr;
	while(fgets(word[max],500,stdin)!=NULL)
	{
		ptr=strchr(word[max],'\n');
		*ptr='\0';
		ptr=word[max];
		while(*ptr=='+'||*ptr=='-')
		{
			if(*ptr=='+')
				tmp++;
			else
				tmp--;
			ptr++;
		}
		for(i=0;i<max;i++)
		{
			if(strcmp(word[i],ptr)==0)
			{
				count[i]+=tmp;
				break;
			}
		}
		if(i==max)
		{
			strcpy(word[max],ptr);
			count[max]=tmp;
			max++;
		}
		tmp=0;
	}
	for(i=0;i<max;i++)
		for(j=0;j<max-i-1;j++)
			if(count[j]<count[j+1])
			{
				strcpy(temp,word[j]);
				strcpy(word[j],word[j+1]);
				strcpy(word[j+1],temp);
				tmp=count[j];
				count[j]=count[j+1];
				count[j+1]=tmp;
			}
	for(i=0;i<max;i++)
	{
		if(count[i]!=0)
			printf("%s %d\n",word[i],count[i]);
	}
	return 0;
}

