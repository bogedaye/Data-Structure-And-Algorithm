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
int fa[2111111];
char s[2111111];
int main()
{
	scanf("%s",s+1);
	fa[0]=-1;
	int n=strlen(s+1);
	for(int i=2;i<=n;++i)
	{
		int p=fa[i-1];
		while(p!=-1&&s[p+1]!=s[i])p=fa[p];
		fa[i]=p+1;
	}
	for(int i=1;i<=n;++i)
		if(fa[i]+fa[i]<i)printf("%d%c",fa[i]," \n"[i==n]);
			else
			{
				int l=i-fa[i];
				printf("%d%c",fa[fa[i]-(fa[i]-(i+1)/2)/l*l]," \n"[i==n]);
			}
	return 0;
}

