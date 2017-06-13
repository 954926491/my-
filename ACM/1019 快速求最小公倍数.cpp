#include <stdio.h>
#include <string.h>
int num[100005];
int gcd(int a,int b)
{
	int t;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	if(a%b==0)
	{
		return b;
	}
	else
	{
		return gcd(b,a%b);
	}
}
int lcm(int* a,int n)
{
	int x,y,m=num[1],i,k;
	for(i=1;(i+1)<=n;i++)
	{
		x=m;
		y=a[i+1];
		k=gcd(x,y);
		m=x/k*y/k*k;
	}
	return m;
}
int main()
{
	int n,i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		scanf("%d",&num[i]);
		int m=lcm(num,n);
		printf("%d\n",m);
	}
	return 0;
}