#include <stdio.h>

int main()
{
	int total=0,nw=1,len=0,lenmax=0,i=0,state=0,ldigit[26],maxl=0,minl=0,maxld=0,minld=0,c;
	float lf=0,avglf=0,maxlf=0,minlf=0;
	for(i=0;i<26;i++)
		ldigit[i]=0;	//init
	while((c=getchar())!=EOF)
	{
		if(c==' '||c=='\t'||c=='\n')
		{
			if(state!=2)
				printf("\n");
			state=0;
			len=0;
		}
		else if(state==0)
		{
			if(c>='a'&&c<='z')
			{
				nw++;
				len++;
				state=1;
				printf("%c",c);
			}
			else if(c>='A'&&c<='Z')
			{
				nw++;
				len++;
				state=1;
				printf("%c",c);
			}
			else 
				state=2;
		}
		else if(state==1)
		{
			len++;
			printf("%c",c);
		}
		if(len>lenmax)
			lenmax=len;
		if(c>='A'&&c<='Z')
		{
			total++;
			ldigit[c-'A']++;
		}
		else if(c>='a'&&c<='z')
		{
			total++;
			ldigit[c-'a']++;
		}
	}
	printf("\n");
	printf("Word count:%d\n",nw);
	printf("The longest:%d\n",lenmax);
	printf("Total:%d\n",total);
	printf("--Alphabet--\n");
	char ch='a';
	if(total==0)
		return 0;
	for(i=0;i<26;i++)
	{
		lf=ldigit[i]/(float)total;
		printf("%c:\t%d\t%.3f\n",ch,ldigit[i],lf);
		avglf+=lf;
		if(i==0)
		{
			maxlf=minlf=lf;
			maxl=minl='a'+i;
			maxld=minld=ldigit[i];
		}
		if(lf>maxlf)
		{
			maxlf=lf;
			maxl='a'+i;
			maxld=ldigit[i];
		}
		if(lf<minlf)
		{
			minlf=lf;
			minl='a'+i;
			minld=ldigit[i];
		}
		ch++;
	}
	avglf/=26;
	printf("Avg=%.3f\n",avglf);
	printf("Max:%c:%d,%.3f\n",maxl,maxld,maxlf);
	printf("Min:%c:%d,%.3f\n",minl,minld,minlf);
	return 0;
}
