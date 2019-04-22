#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc,char *argv[])
{
	FILE *fp=fopen(argv[1],"r");
	char text[100][1000],*ptr;
	int i=0,max=0;
	while(fgets(text[max],100,fp)!=NULL)
	{
		ptr=text[max];
		if(*ptr=='\n')
			*ptr='\0';
		else
		{
			while(*ptr!='\n')
			{
				if(*ptr>='A'&&*ptr<='Z')
					*ptr=tolower(*ptr);
				ptr++;
			}
		}
		max++;
	}
	fp=fopen(argv[1],"w");
	for(i=0;i<max;i++)
		fprintf(fp,"%s",text[i]);
	return 0;
}
