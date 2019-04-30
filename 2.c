#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char *argv[])
{
	int mode=0,i;
	char text[1000],ltext[1000],*ptr;
	FILE *fp=fopen(argv[argc-1],"r");
	if(strcmp(argv[1],"-i")==0||strcmp(argv[2],"-i")==0)
		mode++;
	if(strcmp(argv[1],"-x")==0||strcmp(argv[2],"-x")==0)
		mode+=2;
	while(fgets(text,1000,fp)!=NULL)
	{
		if(mode==0)
		{
			ptr=strstr(text,argv[argc-2]);
			if(ptr!=NULL)
				printf("%s",text);
		}
		else if(mode==1)
		{
			for(i=0;argv[argc-2][i]!='\0';i++)
				argv[argc-2][i]=tolower(argv[argc-2][i]);
			for(i=0;text[i]!='\0';i++)
				ltext[i]=tolower(text[i]);
			ptr=strstr(ltext,argv[argc-2]);
			if(ptr!=NULL)
				printf("%s",text);
		}
		else if(mode==2)
		{
			if(strcmp(text,argv[argc-2])=='\n')
				printf("%s",text);
		}
		else if(mode==3)
		{
			for(i=0;argv[argc-2][i]!='\0';i++)
				argv[argc-2][i]=tolower(argv[argc-2][i]);
			for(i=0;text[i]!='\0';i++)
				ltext[i]=tolower(text[i]);
			if(strcmp(ltext,argv[argc-2])=='\n')
				printf("%s",text);
		}
	}
	return 0;
}
