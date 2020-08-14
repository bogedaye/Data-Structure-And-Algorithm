#include<bits/stdc++.h>
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
namespace io
{
	int F()
	{
		 int F=1,n=0;
		 char ch;
		 while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		 ch=='-'?F=0:n=ch-'0';
		 while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		 return F?n:-n;
	}
	int G()
	{
		 int F=1,n=0;
		 char ch;
		 while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		 ch=='-'?F=0:n=ch-'0';
		 while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		 return F?n:-n;
	}
}
int R(int l,int r)
{
	return (rand()<<15|rand())%(r-l+1)+l;
}
#define SQ(x) ((x)*(x))
int a[66],x[66],y[66],z[66];
int f[66][66][66][66];
int w(int o,int p,int q,int r)
{
	return SQ(a[o]-x[p])+SQ(a[p]-y[q])+SQ(a[q]-z[r]);
}
int main()
{
	int n=io::F();
	for(int i=1;i<=n;++i)a[i]=io::F();
	for(int i=1;i<=n;++i)x[i]=io::F();
	for(int i=1;i<=n;++i)y[i]=io::F();
	for(int i=1;i<=n;++i)z[i]=io::F();
	for(int i=1;i<=n;++i)
		for(int x=i+2;x<=n+2;++x)
			f[i][i][i][x]=f[i][i][i+1][x]=w(i-1,i,i+1,x);
	for(int i=n;i;--i)
		for(int j=i+1;j<=n;++j)
			for(int d=i;d<=j+1;++d)
				for(int x=j+2;x<=n+2;++x)
				{
					f[i][j][d][x]=-0x3f3f3f3f;
						if(d==i||d==j+1)
						{
							for(int k=i;k<=j;++k)
								for(int D=k+1;D<=j+1;++D)
								{
									int tmp=f[i][k-1][i][D]+f[k+1][j][D][x]+w(i-1,k,j+1,x);
									cmax(f[i][j][d][x],tmp);
								}
						}
						else
						{
							for(int k=d;k<=j;++k)
								for(int D=k+1;D<=j+1;++D)
								{
									int tmp=f[i][k-1][d][D]+f[k+1][j][D][x]+w(i-1,k,j+1,x);
									cmax(f[i][j][d][x],tmp);
								}
						}
				}
	printf("%d\n",f[1][n][1][n+2]);
	return 0;
}

