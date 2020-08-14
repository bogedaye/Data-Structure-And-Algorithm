#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int p[120][240],q[120][240][240];
int f[240][30],g[120][240];
int i,j,k,l,m,n,o,r,t;

int main()
{
	freopen("draw.in","r",stdin);
	freopen("draw.out","w",stdout);
	scanf("%d%d%d",&n,&m,&o);
	if ((n<3) || (4*o-1>m))
	{
		puts("Orz J!!!");
		return 0;
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf("%d",&g[i][j]);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			t=g[i][j],q[i][j][0]=-1e9;
			for (k=1;k<j;k++)
			{
				t=t+g[i][j-k];
				q[i][j][k]=max(q[i][j][k-1],t);
			}
		}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			p[i][j]=p[i][j-1]+g[i][j];
	memset(f,200,sizeof(f));
	for (i=0;i<=m;i++)
		f[i][0]=0;
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=o;j++)
			f[i][j]=f[i-1][j];
		for (j=i-3;j>=0;j=j-2)
			for (k=n-2;k>0;k--)
			{
				r=g[k+1][i-(i-j)/2],t=-1e9;
				for (l=k+2;l<=n;l++)
					t=max(t,r+q[l][i-(i-j)/2][(i-j)/2]),r=r+g[l][i-(i-j)/2];
				if (j)
					for (l=1;l<=o;l++)
						f[i][l]=max(f[i][l],f[j-1][l-1]+t+p[k][i]-p[k][j]);
				else
					f[i][1]=max(f[i][1],t+p[k][i]-p[k][j]);
			}
	}
	printf("%d",f[m][o]);
	return 0;
}
