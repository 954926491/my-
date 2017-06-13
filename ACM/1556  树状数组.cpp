#include <stdio.h>
#include <string.h>
int sum[100005];
int n;
void add(int x,int y)
{
	for(int i=x;i<=n;i=i+(i&(-i)))
	sum[i]+=y;
}
int Sum(int x) 
{
	int m=0;
	for(int i=x;i>0;i=i-(i&(-i)))
	m+=sum[i];
	return m;
}
int main()
{
	int i,j,t,k,m;
	while(~scanf("%d",&n)&&n)
	{
		int a,b;
		memset(sum,0,sizeof(sum));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			add(a,1);
			add(b+1,-1);
		}
		for(i=1;i<=n;i++)
		{
			if(i!=1)
			printf(" ");
		    printf("%d",Sum(i));
		}
		printf("\n");
	}
	return 0;
}