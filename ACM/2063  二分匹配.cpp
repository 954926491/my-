#include <stdio.h>
#include <string.h>
int result[1005];
int state[1005];
int data[1005][1005];
int n;
int find(int a)
{
	for(int i=1;i<=n;i++)
	{
		if(data[a][i]==1&&!state[i])
		{
			state[i]=1;
			if(result[i]==0||find(result[i]))
			{
				result[i]=a;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int i,j,m,t,k;
	while(~scanf("%d%d%d",&t,&k,&n)&&t)
	{
		m=0;
		memset(data,0,sizeof(data));
		memset(result,0,sizeof(result));
		int a,b;
		for(i=1;i<=t;i++)
		{
			scanf("%d%d",&a,&b);
			data[a][b]=1;
		}
		for(i=1;i<=k;i++)
		{
			memset(state,0,sizeof(state));
			if(find(i))
			{
				m++;
			}
		}
		printf("%d\n",m);
	}
	return 0;
}