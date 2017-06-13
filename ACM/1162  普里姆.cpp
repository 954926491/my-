#include <stdio.h>
#include <string.h>
#include <math.h>
#define inf 0x3f3f3f
#define Max 200
int visit[Max];
double low[Max],map[Max][Max];
int point;
void prime()
{
	int i,j,next;
	double min,mincost=0;
	for(i=1;i<=point;i++)
	{
		low[i]=map[1][i];
		visit[i]=0;
	}
	visit[1]=1;
	for(i=2;i<=point;i++)
	{
		min=inf;
		for(j=1;j<=point;j++)
		{
			if(!visit[j]&&min>low[j])
			{
				min=low[j];
				next=j;
			}
		}
		visit[next]=1;
		mincost+=min;
		for(j=1;j<=point;j++)
		{
			if(!visit[j]&&low[j]>map[next][j])
			{
				low[j]=map[next][j];
			}
		}
	}
	printf("%.2lf\n",mincost);
}
int main()
{
	int i,j;
	double a[Max],b[Max];
	while(~scanf("%d",&point))
	{
		for(i=1;i<=point;i++)
		{
			for(j=1;j<=point;j++)
			{
			   if(i==j)
			   map[i][j]=0;
			   else
			   map[i][j]=inf;
			}
		}
		for(i=1;i<=point;i++)
		{
			scanf("%lf%lf",&a[i],&b[i]);
		}
		for(i=1;i<=point;i++)
		{
			for(j=i+1;j<=point;j++)
			map[i][j]=map[j][i]=sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
		}
		prime();
	}
	return 0;
}