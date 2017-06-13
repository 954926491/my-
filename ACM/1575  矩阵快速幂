#include <stdio.h>
#include <string.h>
#define Max 15
struct node
{
	int num[Max][Max];
	node()
	{
		memset(num,0,sizeof(num));
	} 
};
node a,b;
int n,k;
node init(node x,node y)
{
	node c;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			c.num[i][j]=0;
			for(int k=0;k<n;k++)
			{
				c.num[i][j]+=(x.num[i][k]*y.num[k][j]);
			}
			c.num[i][j]%=9973;
		}
	}
	return c;
}
node jen(int n)
{
	node p,m;
	p=b;
	m=a;
	while(n>=1)
	{
		if(n&1)
		p=init(p,m);
		n>>=1;
		m=init(m,m);
	}
	return p;
}
int main()
{
	int i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&a.num[i][j]);
			if(i==j)
			{
				b.num[i][j]=1;
			}
			else
			b.num[i][j]=0;
		}
		node res=jen(k);
		int sum=0;
		for(i=0;i<n;i++)
		{
			sum+=res.num[i][i];
			sum%=9973;
		}
		printf("%d\n",sum);
	}
	return 0;
}