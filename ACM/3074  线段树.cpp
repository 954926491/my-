#include <stdio.h>
#include <string.h>
using namespace std;
#define L(x) (x<<1)
#define R(x) (x<<1|1)
const int mod=1000000007;
const int Max=50005;
int num[Max];
struct node
{
	int l,r;
	long long ans;
}w[3*Max];
void build(int l,int r,int rt)
{
	w[rt].l=l;
	w[rt].r=r;
	if(l==r)
	{
		w[rt].ans=num[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,L(rt));
	build(mid+1,r,R(rt));
	w[rt].ans=(w[L(rt)].ans*w[R(rt)].ans)%mod;
}
long long query(int l,int r,int rt)
{
	if(w[rt].l==l&&w[rt].r==r)
	{
		return w[rt].ans;
	}
	int mid=(w[rt].l+w[rt].r)>>1;
	if(r<=mid)
	{
		return query(l,r,L(rt));
	}
	else if(l>=mid+1)
	{
		return query(l,r,R(rt));
	}
	else
	{
		long long a=query(l,mid,L(rt));
		long long b=query(mid+1,r,R(rt));
		return (a*b)%mod;
	}
} 
void update(int val,int loc,int rt)
{
	if(w[rt].l==loc&&w[rt].r==loc)
	{
		w[rt].ans=val;
		return;
	}
	if(loc<=w[L(rt)].r)
	{
		update(val,loc,L(rt));
	}
	if(loc>=w[R(rt)].l)
	{
		update(val,loc,R(rt));
	}
	w[rt].ans=(w[L(rt)].ans*w[R(rt)].ans)%mod;
}
int main()
{
	int i,j,t,k,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		build(1,n,1);
		scanf("%d",&m);
		int a,b,c;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a==0)
			{
				long long ans=query(b,c,1);
				printf("%I64d\n",ans%mod);
			}
			else
			{
				update(c,b,1);
			}
		}
	}
	return 0;
}