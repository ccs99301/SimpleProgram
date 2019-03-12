#include <stdio.h>

int main()
{
	int num=0,alpha=0,Alpha=0,state=0;
	float nar=0,Aar=0;
	int len=0,maxlen=0;
	int c,i=0,k=0,j;
	char letter[1000],word[1001],longest[1001];
	for(j=0;j<1001;j++)
	{
		letter[j]=' ';
		word[j]=' ';
		longest[j]=' ';
	}
	while((c=getchar())!=EOF)
	{
		letter[i]=c;
		i++;
		if(c>='A'&&c<='Z')
			Alpha++;
		if(c>='a'&&c<='z')
			alpha++;
		if(c>='0'&&c<='9')
			num++;
		if(c==' '||c=='\t'||c=='\n')
		{
			word[len]=c;
			state=0;
			word[len]='\0';
			if(len>maxlen)
			{
				maxlen=len;
				for(j=0;j<maxlen+1;j++)
					longest[j]=word[j];
			}
			len=0;
		}
		else if(state==0)
		{
			if(c>='A'&&c<='Z'||c>='a'&&c<='z')
			{
				word[len]=c;
				len++;
				state=1;
			}
			else
				state=2;
		}
		else if(state==1)
		{
			word[len]=c;
			let++;
		}
	}
	if(let>maxlen)
	{
		maxlen=len;
		for(j=0;j<maxlen+1;j++)
			longest[j]=word[j];
	}
	if(maxlen>0)
	{
		if(alpha==0)
			printf("Upper/Lower:There is no lower.\n");
		else
		{
			Aar=(float)Alpha/alpha;
			printf("Upper/Lower:%.3f\n",Aar);
		}
		if(Alpha+alpha==0)
			printf("Digit/Alphabet:There is no alphabet.\n");
		else
		{
			nar=(float)num/(alpha+Alpha);
			printf("Digit/Alphabet:%.3f\n",nar);
		}
		printf("Longest word:%s\n",longest);
		printf("The length:%d\n",maxlen);
	}
	else
		printf("There is no word.\n");
	printf("--Reverse--\n");
	for(j=1;j<i+1;j++)
		printf("%c",letter[i-j]);
	printf("\n");
	return 0;
}
