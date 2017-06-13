#include <stdio.h>
#include <string.h>
#define mod 9997
int a[3][3],b[3][3],c[3][3],d[3][3]={{5,-7,4},{1,0,0},{0,1,0}};
int sta[]={0,1,2,6,19},n;
void init(int x[][3],int y[][3])
{
	memset(b,0,sizeof(b));
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				b[i][j]=(b[i][j]+(x[i][k]*y[k][j]+mod)%mod+mod)%mod;
			}
		}
	}
	memcpy(y,b,sizeof(b));
}
void jen(int n)
{
	for(;n;n>>=1)
	{
		if(n&1)
		init(c,a);
		init(c,c);
	}
}
int main()
{
	int i,j,t,k,m;
	while(~scanf("%d",&n)&&n)
	{
		if(n<=4)
		printf("%d\n",sta[n]);
		else
		{
			memset(a,0,sizeof(a));
			a[0][0]=a[1][1]=a[2][2]=1;
			memcpy(c,d,sizeof(d));
			jen(n-4);
			printf("%d\n",((a[0][0]*sta[4])+(a[0][1]*sta[3])+(a[0][2]*sta[2]))%mod);
		}
	}
    return 0;
}