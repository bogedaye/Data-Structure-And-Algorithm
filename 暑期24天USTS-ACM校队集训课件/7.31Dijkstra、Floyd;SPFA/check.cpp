#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int d[20][20],f[300000][20],g[300000],h[300000];
int i,j,k,m,n,s,x,y,z,sum_edge;

int main()
{
	freopen("check.in","r",stdin);
	freopen("check.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(d,12,sizeof(d));
	for (i=1;i<=n;i++)
		d[i][i]=0;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		d[x][y]=min(d[x][y],z),d[y][x]=min(d[y][x],z);
	}
	for (k=1;k<=n;k++)
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	memset(f,12,sizeof(f));
	f[1][1]=0;
	for (i=3;i<(1<<n);i=i+2)
		for (j=1;j<=n;j++)
			if (i&(1<<(j-1)))
				for (k=1;k<=n;k++)
					if ((j!=k) && (i&(1<<(k-1))))
						f[i][j]=min(f[i][j],f[i-(1<<(j-1))][k]+d[j][k]);
	memset(g,12,sizeof(g));
	for (i=(1<<n)-1;i>0;i--)
	{
		for (j=1;j<=n;j++)
			g[i]=min(g[i],f[i][j]);
		h[i]=g[i];
		for (j=1;j<=n;j++)
			if (! (i&(1<<(j-1))))
				h[i]=min(h[i],h[i+(1<<(j-1))]);
	}
	s=f[0][0];
	for (i=1;i<(1<<n);i++)
		s=min(s,max(g[i],h[(1<<n)-1-i]));
	printf("%d",s);
	return 0;
}
