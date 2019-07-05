#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(const void *s1,const void *s2)
{
	return *(int *)s1-*(int *)s2;
}
void insertion(int data[],int len)
{
	int i,j,tmp;
	for(i=1;i<len;i++)
	{
		tmp=data[i];
		for(j=i-1;j>=0&&data[j]>tmp;j--)
			data[j+1]=data[j];
		data[j+1]=tmp;
	}
}
void selection(int data[],int len)
{
	int i,j,tmp,min;
	for(i=0;i<len-1;i++)
	{
		min=i;
		for(j=i+1;j<len;j++)
			if(data[min]>data[j])
				min=j;
		tmp=data[min];
		data[min]=data[i];
		data[i]=tmp;
	}
}
void bubble(int data[],int len)
{
	int i,j,tmp;
	for(i=0;i<len-1;i++)
		for(j=0;j<len-i-1;j++)
			if(data[j]>data[j+1])
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
}
int main()
{
	int rad[1000],rad2[10000],rad3[100000],*rad4;
	int data[1000],data2[10000],data3[100000],*data4,i,j;
	double stime,rtime[4][5];
	rad4=(int *)malloc(1000000*sizeof(int));
	data4=(int *)malloc(1000000*sizeof(int));
	srand(time(NULL));
	for(i=0;i<1000;i++)
		rad[i]=rand();
	rtime[0][0]=0;
	for(i=0;i<10000;i++)
	{
		for(j=0;j<1000;j++)
			data[j]=rad[j];
		stime=time(NULL);
		insertion(data,1000);
		rtime[0][0]+=time(NULL)-stime;
	}
	rtime[0][0]/=10000;
	printf("Insertion Sort\nBefore\t\t\tAfter\n");
	for(i=0;i<100;i++)
		printf("%d\t\t\t%d\n",rad[i],data[i]);
	rtime[0][1]=0;
	for(i=0;i<10000;i++)
	{
		for(j=0;j<1000;j++)
			data[j]=rad[j];
		stime=time(NULL);
		selection(data,1000);
		rtime[0][1]+=time(NULL)-stime;
	}
	rtime[0][1]/=10000;
	printf("Selection Sort\nBefore\t\t\tAfter\n");
	for(i=0;i<100;i++)
		printf("%d\t\t\t%d\n",rad[i],data[i]);
	rtime[0][2]=0;
	for(i=0;i<10000;i++)
	{
		for(j=0;j<1000;j++)
			data[j]=rad[j];
		stime=time(NULL);
		bubble(data,1000);
		rtime[0][2]+=time(NULL)-stime;
	}
	rtime[0][2]/=10000;
	printf("Bubble Sort\nBefore\t\t\tAfter\n");
	for(i=0;i<100;i++)
		printf("%d\t\t\t%d\n",rad[i],data[i]);
	rtime[0][3]=0;
	for(i=0;i<10000;i++)
	{
		for(j=0;j<1000;j++)
			data[j]=rad[j];
		stime=time(NULL);
		mergesort(data,1000,sizeof(int),cmp);
		rtime[0][3]+=time(NULL)-stime;
	}
	rtime[0][3]/=10000;
	printf("Merge Sort\nBefore\t\t\tAfter\n");
	for(i=0;i<100;i++)
		printf("%d\t\t\t%d\n",rad[i],data[i]);
	rtime[0][4]=0;
	for(i=0;i<10000;i++)
	{
		for(j=0;j<1000;j++)
			data[j]=rad[j];
		stime=time(NULL);
		qsort(data,1000,sizeof(int),cmp);
		rtime[0][4]+=time(NULL)-stime;
	}
	rtime[0][4]/=10000;
	printf("Quick Sort\nBefore\t\t\tAfter\n");
	for(i=0;i<100;i++)
		printf("%d\t\t\t%d\n",rad[i],data[i]);
	for(i=0;i<10000;i++)
		rad2[i]=rand();
	rtime[1][0]=0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<10000;j++)
			data2[j]=rad2[j];
		stime=time(NULL);
		insertion(data2,10000);
		rtime[1][0]+=time(NULL)-stime;
	}
	rtime[1][0]/=100;
	rtime[1][1]=0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<10000;j++)
			data2[j]=rad2[j];
		stime=time(NULL);
		selection(data2,10000);
		rtime[1][1]+=time(NULL)-stime;
	}
	rtime[1][1]/=100;
	rtime[1][2]=0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<10000;j++)
			data2[j]=rad2[j];
		stime=time(NULL);
		bubble(data2,10000);
		rtime[1][2]+=time(NULL)-stime;
	}
	rtime[1][2]/=100;
	rtime[1][3]=0;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<10000;j++)
			data2[j]=rad2[j];
		stime=time(NULL);
		mergesort(data2,10000,sizeof(int),cmp);
		rtime[1][3]+=time(NULL)-stime;
	}
	rtime[1][3]/=1000;
	rtime[1][4]=0;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<10000;j++)
			data2[j]=rad2[j];
		stime=time(NULL);
		qsort(data2,10000,sizeof(int),cmp);
		rtime[1][4]+=time(NULL)-stime;
	}
	rtime[1][4]/=1000;
	for(i=0;i<100000;i++)
		rad3[i]=rand();
	rtime[2][0]=0;
	for(j=0;j<100000;j++)
		data3[j]=rad3[j];
	stime=time(NULL);
	insertion(data3,100000);
	rtime[2][0]+=time(NULL)-stime;
	rtime[2][1]=0;
	for(j=0;j<100000;j++)
		data3[j]=rad3[j];
	stime=time(NULL);
	selection(data3,100000);
	rtime[2][1]+=time(NULL)-stime;
	rtime[2][2]=0;
	for(j=0;j<100000;j++)
		data3[j]=rad3[j];
	stime=time(NULL);
	bubble(data3,100000);
	rtime[2][2]+=time(NULL)-stime;
	rtime[2][3]=0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<100000;j++)
			data3[j]=rad3[j];
		stime=time(NULL);
		mergesort(data3,100000,sizeof(int),cmp);
		rtime[2][3]+=time(NULL)-stime;
	}
	rtime[2][3]/=100;
	rtime[2][4]=0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<100000;j++)
			data3[j]=rad3[j];
		stime=time(NULL);
		qsort(data3,100000,sizeof(int),cmp);
		rtime[2][4]+=time(NULL)-stime;
	}
	rtime[2][4]/=100;
	for(i=0;i<1000000;i++)
		rad4[i]=rand();
	rtime[3][3]=0;
	rtime[3][4]=0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<1000000;j++)
			data4[j]=rad4[j];
		stime=time(NULL);
		mergesort(data4,1000000,sizeof(int),cmp);
		rtime[3][3]+=time(NULL)-stime;		
		for(j=0;j<1000000;j++)
			data4[j]=rad4[j];
		stime=time(NULL);
		qsort(data4,1000000,sizeof(int),cmp);
		rtime[3][4]+=time(NULL)-stime;
	}
	rtime[3][3]/=100;
	rtime[3][4]/=100;
	printf("\t\t1000\t10000\t100000\t1000000\n");
	printf("Insertion Sort\t%lf\t%lf\t%lf\tX\n",rtime[0][0],rtime[1][0],rtime[2][0]);
	printf("Selection Sort\t%lf\t%lf\t%lf\tX\n",rtime[0][1],rtime[1][1],rtime[2][1]);
	printf("Bubble Sort\t%lf\t%lf\t%lf\tX\n",rtime[0][2],rtime[1][2],rtime[2][2]);
	printf("Merge Sort\t%lf\t%lf\t%lf\t%lf\n",rtime[0][3],rtime[1][3],rtime[2][3],rtime[3][3]);
	printf("Quick Sort\t%lf\t%lf\t%lf\t%lf\n",rtime[0][4],rtime[1][4],rtime[2][4],rtime[3][4]);
	return 0;
}

