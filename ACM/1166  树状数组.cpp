#include <stdio.h>
#include <string.h>
int sum[50005];
int n;
void add(int x,int y)
{
	for(int i=x;i<=n;i=i+(i&(-i)))
	{
		sum[i]+=y;
	}
}
void sub(int x,int y)
{
	for(int i=x;i<=n;i=i+(i&(-i)))
	{
		sum[i]-=y;
	}
}
int querry(int x)
{
	int m=0;
	for(int i=x;i>0;i=i-(i&(-i)))
	{
		m+=sum[i];
	}
	return m;
}
int main()
{
	int i,j,t,k,m,num=1;
	scanf("%d",&t);
	char c[20];
	while(t--)
	{
		scanf("%d",&n);
		memset(sum,0,sizeof(sum));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			add(i,m);
		}
		printf("Case %d:\n",num++);
		while(1)
		{
			int a,b;
			scanf("%s",c);
			if(c[0]=='E')
			break;
			scanf("%d%d",&a,&b);
			if(c[0]=='A')
			{
				add(a,b);
			}
			if(c[0]=='S')
			{
				sub(a,b);
			}	
			if(c[0]=='Q')
			{
				printf("%d\n",querry(b)-querry(a-1));
			}
		}
	}
	return 0;
}