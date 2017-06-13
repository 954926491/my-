#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define inf 0x3f3f3f
const int maxn=100000;
const int maxh=1000;
typedef struct node
{
	int to,next,w;
};
typedef struct dep
{
	int x,t;
};
node E[maxn];
int head[maxh],headx[maxh],deep[maxh],cnt;
void init()
{
	memset(head,-1,sizeof(head));
	cnt=0;
}
void add(int a,int b,int c)
{
	E[cnt].to=b,E[cnt].w=c,E[cnt].next=head[a],head[a]=cnt++;
	E[cnt].to=a,E[cnt].w=0,E[cnt].next=head[b],head[b]=cnt++;
}
int min(int a,int b)
{
	if(a>b)
	return b;
	return a;
}
bool bfs(int s,int t,int n)
{
	memset(deep,-1,sizeof(deep));
	queue<dep>q;
	dep fir,nex;
	fir.x=s;
	fir.t=0;
	deep[s]=0;
	q.push(fir);
	while(!q.empty())
	{
		fir=q.front();
		q.pop();
		for(int i=head[fir.x];i+1;i=E[i].next)
		{
			nex.x=E[i].to;
			nex.t=fir.t+1;
			if(deep[nex.x]!=-1||!E[i].w)
			{
				continue;
			}
			deep[nex.x]=nex.t;
			q.push(nex);
		}
	}
	for(int i=1;i<=n;i++)
	headx[i]=head[i];
	return deep[t]!=-1;
}
int dfs(int s,int t,int flow)
{
	if(s==t)
	return flow;
	int newflow=0;
	for(int i=headx[s];i+1;i=E[i].next)
	{
	    headx[s]=i;
	    int to=E[i].to;
	    int w=E[i].w;
	    if(deep[to]!=deep[s]+1||!E[i].w)
	    {
    		continue;
    	}
    	int temp=dfs(to,t,min(w,flow-newflow));
    	newflow+=temp;
    	E[i].w-=temp;
    	E[i^1].w+=temp;
    	if(newflow==flow)
    	break;
	}
	if(!newflow)
	deep[s]=0;
	return newflow;
}
int Dinic(int s,int t,int n)
{
	int sum=0;
	while(bfs(s,t,n))
	{
		sum+=dfs(s,t,inf);
	}
	return sum;
}
int main()
{
	int a,b,c,n,m;
	while(~scanf("%d%d",&m,&n))
	{
		init();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,0);
		}
		printf("%d\n",Dinic(1,n,n+10));
	}
	return 0;
}