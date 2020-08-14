#include <cstdio>

int d[1200000],f[1200000];
int i,j,m,n,t,fx,fy;
long long s;

inline int getfather(int x)
{
	if (f[x]==x)
		return x;
	else
		return f[x]=getfather(f[x]);
}

int main()
{
//	freopen("t3.in","r",stdin);
//	freopen("t3.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		f[i]=i;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if (d[t])
		{
			s=s+t;
			f[i]=d[t];
		}
		else
			d[t]=i;
	}
	for (i=(1<<m)-1;i>=0;i--)
		for (j=1;j<=m;j++)
			if ((! (i&(1<<(j-1)))) && (d[i|(1<<(j-1))]))
				if (! d[i])
					d[i]=d[i|(1<<(j-1))];
				else
				{
					fx=getfather(d[i]);
					fy=getfather(d[i|(1<<(j-1))]);
					if (fx!=fy)
					{
						f[fy]=fx;
						s=s+i;
					}
				}
	printf("%I64d",s);
	return 0;
}
