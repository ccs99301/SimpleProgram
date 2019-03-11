#include <stdio.h>

float grade(float x)
{
	float y=0,z=0;
	while(1)
	{
		y=y+0.001;
		z=y*y;
		if(z>=x)
			break;
	}
	y*=10;
	return y;
}

int main()
{
	int i=0,c=0,j=0;
	int id[1000];
	float cscore[1000],pscore[1000],lscore[1000],avg[1000];
	float maxc,maxp,maxl,minc,minp,minl,ttc=0,ttp=0,ttl=0,cavg=0,pavg=0,lavg=0;
	int pn=0,fnum=0,snum=0,tnum=0;
	int len=0,state=0;
	float tmp;
	int th=0,sub=1;
	while((c=getchar())!=EOF)
	{
		id[j]=j;
		if(c==' '||c=='\t'||c=='\n')
		{
			state=0;
			if(sub==1)
			{
				if(len==1)
					cscore[j]=fnum;
				else if(len==2)
					cscore[j]=fnum*10+snum;
				else if(len==3)
					cscore[j]=fnum*100+snum*10+tnum;
				if(pn==1)
					cscore[j]=0;
				if(cscore[j]>100)
					cscore[j]=100;
				sub=2;
			}
			else if(sub==2)
			{
				if(len==1)
					pscore[j]=fnum;
				else if(let==2)
					pscore[j]=fnum*10+snum;
				else if(len==3)
					pscore[j]=fnum*100+snum*10+tnum;
				if(pn==1)
					pscore[j]=0;
				if(pscore[j]>100)
					pscore[j]=100;
				sub=3;
			}
			else if(sub==3)
			{
				if(len==1)
					lscore[j]=fnum;
				else if(len==2)
					lscore[j]=fnum*10+snum;
				else if(len==3)
					lscore[j]=fnum*100+snum*10+tnum;
				if(pn==1)
					lscore[j]=0;
				if(lscore[j]>100)
					lscore[j]=100;
				sub=1;
			}
			if(c=='\n')
				j++;
			pn=len=0;
		}
		else if(c=='-')
		{
			pn=1;
		}
		else if(state==0)
		{
			fnum=c-'0';
			len=1;
			state=1;
		}
		else if(state==1)
		{
			snum=c-'0';
			len=2;
			state=2;
		}
		else if(state==2)
		{
			tnum=c-'0';
			len=3;
			state=3;
		}
	}
	for(i=0;i<j;i++)
	{
		cscore[i]=(grade(cscore[i]));
		pscore[i]=(grade(pscore[i]));
		lscore[i]=(grade(lscore[i]));
		avg[i]=(cscore[i]+pscore[i]+lscore[i])/3;
	}
	printf("ID\t| Calculus\t| Programming\t| Linear Algebra\t| Average\n");
	printf("--------------------------------------------------------------------------\n");
	maxc=cscore[0];
	minc=cscore[0];
	maxp=pscore[0];
	minp=pscore[0];
	maxl=lscore[0];
	minl=lscore[0];
	for(i=0;i<j;i++)
	{
		while(i+th!=j+1)
		{
			if(avg[i]<avg[i+th])
				{
					tmp=avg[i];
					avg[i]=avg[i+th];
					avg[i+th]=tmp;
					tmp=cscore[i];
					cscore[i]=cscore[i+th];
					cscore[i+th]=tmp;
					tmp=pscore[i];
					pscore[i]=pscore[i+th];
					pscore[i+th]=tmp;
					tmp=lscore[i];
					lscore[i]=lscore[i+th];
					lscore[i+th]=tmp;
					tmp=id[i];
					id[i]=id[i+th];
					id[i+th]=tmp;
				}
			th++;
		}
		printf("%d\t| %.1f\t\t| %.1f\t\t| %.1f\t\t\t| %.1f\n",id[i],cscore[i],pscore[i],lscore[i],avg[i]);
		th=0;
		if(cscore[i]>maxc)
			maxc=cscore[i];
		if(pscore[i]>maxp)
			maxp=pscore[i];
		if(lscore[i]>maxl)
			maxl=lscore[i];
		if(cscore[i]<minc)
			minc=cscore[i];
		if(pscore[i]<minp)
			minp=pscore[i];
		if(lscore[i]<minl)
			minl=lscore[i];
	}
	for(i=0;i<j;i++)
	{
		ttc+=cscore[i];
		ttp+=pscore[i];
		ttl+=lscore[i];
	}
	cavg=ttc/j;
	pavg=ttp/j;
	lavg=ttl/j;
	printf("--------------------------------------------------------------------------\n");
	printf("Max\t| %.1f\t\t| %.1f\t\t| %.1f\n",maxc,maxp,maxl);
	printf("Min\t| %.1f\t\t| %.1f\t\t| %.1f\n",minc,minp,minl);
	printf("Avg\t| %.1f\t\t| %.1f\t\t| %.1f\n",cavg,pavg,lavg);
	return 0;
}
