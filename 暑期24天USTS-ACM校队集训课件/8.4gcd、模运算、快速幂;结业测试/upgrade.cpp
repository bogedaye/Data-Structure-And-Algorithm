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
const int M=1000000007;
int ex(int b,long long e=M-2)
{
	e%=M-1;
	int ans=1;
	for(;e;e>>=1,b=1ll*b*b%M)
		if(e&1)ans=1ll*ans*b%M;
	return ans;
}
int siz;
struct mat
{
	int a[111][111];
}O,I,base;
mat operator *(const mat &x,const mat &y)
{
	mat z=O;
	for(int i=1;i<=siz;++i)
		for(int k=1;k<=siz;++k)
		{
			long long X=x.a[i][k];
			const int *Y=y.a[k];
			int *Z=z.a[i];
			for(int j=1;j<=siz;++j)
				Z[j]=(Z[j]+X*Y[j])%M;
		}
	return z;
}
mat ex(mat b,long long e)
{
	mat ans=I;
	for(;e;e>>=1,b=b*b)
		if(e&1)ans=ans*b;
	return ans;
}
int v[111];
int main()
{
	long long n=io::G(),a=io::G();
	int p=io::F(),q=io::F();
	if(p==q)
	{
		printf("%lld\n",n%M);
		return 0;
	}
	p=1ll*p*ex(q)%M;
	int P=ex(p);
	if(n==a)
	{
		printf("%d\n",ex(P,n));
		return 0;
	}
	if(a==0)
	{
		printf("%lld\n",1ll*P*(n%M)%M);
		return 0;
	}
	siz=a+2; 
	for(int i=1;i<=a+2;++i)
		I.a[i][i]=1;
	for(int i=2;i<siz;++i)
		base.a[i][i-1]=1;
	base.a[siz][siz]=1;
	base.a[1][1]=base.a[1][siz]=P;
	base.a[1][siz-1]=1ll*(p-1)*P%M;
	int sum=P;
	v[0]=P;
	for(int i=1;i<=a;++i)
	{
		v[i]=(P+1ll*(M+1-p)*P%M*sum)%M;
		sum=(sum+v[i])%M;
		v[i]=sum;
	}
	mat d=ex(base,n-(a+1));
	int ans=d.a[1][siz];
	for(int i=1;i<=a+1;++i)
		ans=(ans+1ll*d.a[1][i]*v[a+1-i])%M;
	printf("%d\n",ans);
	return 0;
}

