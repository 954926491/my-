#include <stdio.h>
#include <string.h>
using namespace std;
#define Maxn 1000005
#define Maxh 100005
struct node
{
	int to,next;
}w[Maxn];
int stact[Maxh],head[Maxh],dfn[Maxh],low[Maxh];
bool instact[Maxh];
int cnt,top,num,sum;
int min(int a,int b)
{
	if(a>b)
	return b;
	return a;
}
void add(int a,int b)
{
	w[cnt].to=b,w[cnt].next=head[a],head[a]=cnt++;
}
void init()
{
	memset(head,-1,sizeof(head));
	memset(instact,false,sizeof(instact));
	memset(dfn,0,sizeof(dfn));
	cnt=0;
	top=0;
	num=0;
	sum=0;
}
void tarjan(int i)
{
	int j;
	dfn[i]=low[i]=++num;
	instact[i]=true;
	stact[top++]=i;
	for(int k=head[i];k+1;k=w[k].next)
	{
		j=w[k].to;
		if(!dfn[j])
		{
			tarjan(j);
			low[i]=min(low[i],low[j]);
		}
		if(dfn[j]&&dfn[j]<low[i])
		{
			low[i]=dfn[j];
		}
	}
		if(dfn[i]==low[i])
		{
			sum++;
			do{
			      j=stact[top--];
  	              instact[j]=false;
			  }while(j!=i);
		}
}
int main()
{
	int i,j,t,k,n,m;
	while(~scanf("%d%d",&n,&m)&&(n||m))
	{
		init();
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&t,&k);
			add(t,k);
		}
		for(i=1;i<=n;i++)
		{
			if(!dfn[i])
			tarjan(i);
		}
		if(sum>1)
		printf("No\n");
		else
		printf("Yes\n"); 
	}
	return 0;
}