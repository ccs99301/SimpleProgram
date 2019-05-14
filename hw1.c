#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char *argv[])
{
	int i=0,modei=0,modea=0;
	char text[2000],ntext[2000],ltext[2000],*ptr;
	for(i=0;i<2000;i++)
	{
		text[i]='\0';
		ntext[i]='\0';
		ltext[i]='\0';
	}
	for(i=1;i<argc;i++)
		if(argv[i][0]=='-')
		{
			if(argv[i][1]=='i')
				modei=1;
			else if(argv[i][1]=='a')
				modea=1;
		}
	if(argc>2&&argc<6)
	{
		while(fgets(text,2000,stdin)!=NULL)
		{
			if(modei==0)
			{
				ptr=strstr(text,argv[argc-2]);
				if(ptr!=NULL)
				{
					strncpy(ntext,text,strlen(text)-strlen(ptr));
					strcat(ntext,argv[argc-1]);
					ptr+=strlen(argv[argc-2]);
					strcat(ntext,ptr);
				}
				else
					strcpy(ntext,text);
				while(modea==1&&ptr!=NULL)
				{
					strcpy(text,ntext);
					ptr=strstr(text,argv[argc-2]);
					if(ptr!=NULL)
					{
						for(i=0;ntext[i]!='\0';i++)
							ntext[i]='\0';
						strncpy(ntext,text,strlen(text)-strlen(ptr));
						strcat(ntext,argv[argc-1]);
						ptr+=strlen(argv[argc-2]);
						strcat(ntext,ptr);
					}
				}
			}
			else
			{
				for(i=0;text[i]!='\0';i++)
					ltext[i]=tolower(text[i]);
				for(i=0;i<strlen(argv[argc-2]);i++)
					argv[argc-2][i]=tolower(argv[argc-2][i]);
				ptr=strstr(ltext,argv[argc-2]);
				if(ptr!=NULL)
				{
					strncpy(ntext,text,strlen(text)-strlen(ptr));
					strcat(ntext,argv[argc-1]);
					ptr+=strlen(argv[argc-2]);
					ptr=text+strlen(text)-strlen(ptr);
					strcat(ntext,ptr);
				}
				else
					strcpy(ntext,text);
				while(modea==1&&ptr!=NULL)
				{
					strcpy(text,ntext);
					for(i=0;text[i]!='\0';i++)
						ltext[i]=tolower(text[i]);
					ptr=strstr(ltext,argv[argc-2]);
					if(ptr!=NULL)
					{
						for(i=0;ntext[i]!='\0';i++)
							ntext[i]='\0';
						strncpy(ntext,text,strlen(text)-strlen(ptr));
						strcat(ntext,argv[argc-1]);
						ptr+=strlen(argv[argc-2]);
						ptr=text+strlen(text)-strlen(ptr);
						strcat(ntext,ptr);
					}
				}
			}
			printf("%s",ntext);
			for(i=0;ntext[i]!='\0';i++)
			{
				ntext[i]='\0';
				ltext[i]='\0';
			}
		}
	}
	return 0;
}

