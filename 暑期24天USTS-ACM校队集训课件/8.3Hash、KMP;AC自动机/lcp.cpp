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
	long long G()
	{
		 long long F=1,n=0;
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
const long long M=100000000000031LL;
const int k=1013;
char s[2222][2222];
long long h[2222][2222];
long long v[2222][2222];
long long d[2222][2222];
long long pw[2222];
struct init
{
	init() //³õÊ¼»¯ 
	{
		pw[0]=1;
		for(int i=1;i<=2004;++i)
			pw[i]=1ll*pw[i-1]*k%M;
	}
}INIT;
inline long long tm(long long x,long long y)
{
	long long ans=0;
	for(;x;x>>=15,y=(y<<15)%M)
		ans=(ans+(x&(1<<15)-1)*y)%M;
	return ans;
}
int geth(int x,int y,int l)
{
	long long t=(h[x][y+l-1]+M-h[x][y-1])%M;
	t=tm(t,pw[2000-(y+l-1)]);
	return t;
}
int getv(int x,int y,int l)
{
	long long t=(v[x+l-1][y]+M-v[x-1][y])%M;
	t=tm(t,pw[2000-(x+l-1)]);
	return t;
}
int getd(int x,int y,int l)
{
	long long t=(d[x+l-1][y+l-1]+M-d[x-1][y-1])%M;
	t=tm(t,pw[2000-(dmin(x,y)+l-1)]);
	return t;
} 
int main()
{
	int n=io::F(),m=io::F(),q=io::F();
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1); 
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			h[i][j]=(h[i][j-1]+s[i][j]*pw[j-1])%M,
			v[i][j]=(v[i-1][j]+s[i][j]*pw[i-1])%M,
			d[i][j]=(d[i-1][j-1]+s[i][j]*pw[dmin(i,j)-1])%M;
	for(int i=1;i<=q;++i)
	{
		int a,b,x,y;
		char c[3],z[3];
		a=io::F(),b=io::F();
		scanf("%s",c);
		x=io::F(),y=io::F();
		scanf("%s",z);
		long long H1,H2;
		int maxlen=n;
		if(c[0]!='V')cmin(maxlen,m-b+1);
		if(c[0]!='H')cmin(maxlen,n-a+1);
		if(z[0]!='V')cmin(maxlen,m-y+1);
		if(z[0]!='H')cmin(maxlen,n-x+1);
		int ans=0;
		for(int l=1,r=maxlen,mid=l+r>>1;l<=r;mid=l+r>>1)
		{
			if(c[0]=='H')H1=geth(a,b,mid);
			if(c[0]=='V')H1=getv(a,b,mid);
			if(c[0]=='D')H1=getd(a,b,mid);
			if(z[0]=='H')H2=geth(x,y,mid);
			if(z[0]=='V')H2=getv(x,y,mid);
			if(z[0]=='D')H2=getd(x,y,mid);
			if(H1==H2)ans=mid,l=mid+1;
				else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

