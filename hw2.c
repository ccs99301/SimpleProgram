#include <stdio.h>

int main()
{
		int total;
		int c;
		int vowel;
		int num;
		int n;

		while ((c=getchar()) != EOF)
		{
				total++;
				if(c=='a' || c=='A')
				{
				vowel++;
				}
				if(c=='e' || c=='E')
				{
				vowel++;
				}
				if(c=='i' || c=='I')
				{
				vowel++;
				}
				if(c=='o' || c=='O')
				{
				vowel++;
				}
				if(c=='u' || c=='U')
				{
				vowel++;
				}
				if(c>='0' && c<='9')
				{
				num++;
				}
				if(c=='\n')
				{
				n++;
				}
		}
		printf("Total characters:%d\n",total);
		printf("Total rows:%d\n",n);
		printf("Number:%d\n",num);
		printf("Vowel:%d\n",vowel);
		return 0;
}
