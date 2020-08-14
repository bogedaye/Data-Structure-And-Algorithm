#include <cstdio>
#include <cstring>

const int p=998244353;
const int inv_100=828542813;
int d[30],f[120000],g[120000];
char c[120000];
int i,j,n,r,s,t;

int main()
{
	freopen("sub.in","r",stdin);
	freopen("sub.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",c+1);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&g[i]);
		g[i]=1LL*(100-g[i])*inv_100%p;
	}
	s=1;
	f[0]=1;
	for (i=1;i<=26;i++)
		d[i]=1;
	for (i=1;i<=n;i++)
	{
		f[i]=1LL*d[c[i]-96]*g[i]%p;
		for (j=1;j<=26;j++)
			if (j!=c[i]-96)
				d[j]=(d[j]+f[i])%p;
		s=(s+f[i])%p;
	}
	printf("%d",s);
	return 0;
}
