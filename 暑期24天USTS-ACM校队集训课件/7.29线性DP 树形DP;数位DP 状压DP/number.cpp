#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int p=1000000007;
int p8[1200];
int f[1200],g[1200];
int i,j,k,l,o,p1,p2,p3,q,t,t1,t2,u,v,p2_inv;
char c;



inline void input()
{
	o=0,c=getchar();
	while (! ((c>47) && (c<58)))
		c=getchar();
	while ((c>47) && (c<58))
		o++,g[o]=c-48,c=getchar();
	for (i=1;i<=o/2;i++)
		swap(g[i],g[o-i+1]);
	return;
}

inline int check()
{
	t=0;
	for (int i=1;i<=o;i++)
		if ((g[i]==4) || (g[i]==7))
		{
			if ((t) && (i-t<=k))
				return 1;
			t=i;
		}
	return 0;
}

inline void pre_dp()
{
	for (p8[0]=1,i=1;i<=1000;i++)
		p8[i]=8LL*p8[i-1]%p;
	f[0]=1;
	for (i=1;i<=1000;i++)
	{
		f[i]=p8[i-1]*2%p;
		if (i-k-1>0){
			for(j=1;j<=i-k-1;j++)
			f[i]=(f[i]+2ll*f[j]*p8[i-j-1])%p;
		}
		
//			f[i]=(f[i]+2LL*h[i-k-1]*p8_inv[1000-(i-1)])%p;
//		h[i]=(h[i-1]+1LL*f[i]*p8[1000-i])%p;
	}
	return;
}

inline int calc()
{
	input();
	u=(p-check())%p,v=0,t=o+o+k;
	for (i=o;i>0;i--)
	{
		p1=0,p2=p8[i-1],p3=0;
		if (t-k>i)
		{
			p1=p8[i-1];
			if (i>k+1){
				for(j=1;j<=i-k-1;j++)
				p1=(p1+1ll*f[j]*p8[i-j-1])%p;
			}
//				p1=(p1+1LL*h[i-k-1]*p8_inv[1000-(i-1)])%p;
		}
		if (min(i-1,t-k-1)>0){
			for(j=1;j<=min(i-1,t-k-1);j++)
			p2=(p2+1ll*f[j]*p8[i-j-1])%p;
		}
//			p2=(p2+1LL*h[min(i-1,t-k-1)]*p8_inv[1000-(i-1)])%p;
		if (g[i]>4)
			p3++;
		if (g[i]>7)
			p3++;
		u=(u+1LL*p3*p1+1LL*(g[i]-p3)*p2)%p;
		if (((g[i]==4) || (g[i]==7)) && (t-i<=k))
			break;
		if ((g[i]==4) || (g[i]==7))
			t=i;
	}
	for (i=o;i>0;i--)
		v=(v*10LL+g[i])%p;
	return (v-u+p)%p;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&q,&k);
	pre_dp();
	for (l=1;l<=q;l++)
	{
		t1=calc()-check(),t2=calc();
		printf("%d\n",(t2-t1+p)%p);
	}
	return 0;
}
