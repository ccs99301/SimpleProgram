#include <stdio.h>

int main()
{
	int c,state=0;
	while((c=getchar())!=EOF)
	{
		if(state==0&&(c==' '||c=='\t'))
		{
			printf("%c",c);
			state=1;
		}
		else if(state==0)
			printf("%c",c);
		else if(state==1&&(c!=' '||c!='\t'))
		{
			printf("%c",c);
			state=0;
		}
	}
	return 0;
}
