#include <stdio.h>

int main()
{
		int total=0;
		int nl=0;
		int other=0;
		int i;
		int ndigit[10];
		int ldigit[26];
		int c;
		for(i=0;i<10;i++) ndigit[i]=0;
		for(i=0;i<26;i++) ldigit[i]=0;
		while((c=getchar())!=EOF)
		{
				total++;
				if(c>='0'&&c<='9')
				{
						nl++;
						ndigit[c-'0']++;
				}
				else if(c>='A'&&c<='Z')
				{
						nl++;
						ldigit[c-'A']++;
				}
				else if(c>='a'&&c<='z')
				{
						nl++;
						ldigit[c-'a']++;
				}
		}
		other=total-nl;
		printf("Total character:%d\n",total);
		printf("Other character:%d\n",other);
		if(total!=0)
		{
			printf("--number--\n");
			char ch='0';
			for(i=0;i<10;i++)
			{	
					double rate=ndigit[i]/(float)total;
					printf("%c:\t%d\t%.3f\n",ch,ndigit[i],rate);
					ch++;
			}
			printf("--alphabet--\n");
			ch='a';
			for(i=0;i<26;i++)
			{
					double rate=ldigit[i]/(float)total;
					printf("%c:\t%d\t%.3f\n",ch,ldigit[i],rate);
					ch++;
			}
		}
		else printf("error!\n");
		return 0;
}
