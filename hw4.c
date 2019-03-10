#include <stdio.h>

int main()
{
		int total=0;
		int nw=1;
		int let=0;
		int letmax=0;
		int state=1;
		int i;
		int ldigit[26];
		float lf;
		float avglf=0;
		float minlf=0;
		float maxlf=0;
		int maxl=0;
		int minl=0;
		int maxld=0;
		int minld=0;
		int c;
		for(i=0;i<26;i++) ldigit[i]=0;
		while((c=getchar())!=EOF)
		{
				if(c==' '||c=='\t'||c=='\n')
				{
						if(state!=2)
						{
							printf("\n");
						}
						state=0;
						let=0;
				}
				else if(state==0)
				{
						if(c>='a'&&c<='z')
						{
								nw++;
								let++;
								state=1;
								printf("%c",c);
						}
						else if(c>='A'&&c<='Z')
						{
								nw++;
								let++;
								state=1;
								printf("%c",c);
						}
						else 
						{
								state=2;
						}
				}
				else if(state==1)
				{
						let++;
						printf("%c",c);
				}
				if(let>letmax) letmax=let;
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
		printf("The longest:%d\n",letmax);
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
						maxlf=lf;
						minlf=lf;
						maxl='a'+i;
						minl='a'+i;
						maxld=ldigit[i];
						minld=ldigit[i];
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
