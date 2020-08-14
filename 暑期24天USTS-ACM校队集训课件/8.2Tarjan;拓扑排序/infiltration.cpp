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
struct edge
{
	int to;
	int next;
}e[555555],d[555555];
int pe=111111,pd=111111;
void insert(edge* e,int a,int to,int& pe)
{
	e[pe]=(edge){to,e[a].next};
	e[a].next=pe++;
}
int a[111111];
long long sum[111111];
int dfn[111111],dfc,top[111111],bl[111111],pb;
int s[111111],ts;
int deg[111111],q[111111],hq,tq;
void dfs(int o)
{
	top[o]=dfn[o]=++dfc;
	s[++ts]=o;
	for(register int p=e[o].next;p;p=e[p].next)
		if(!dfn[e[p].to])
		{
			dfs(e[p].to);
			cmin(top[o],top[e[p].to]);
		}
		else if(!bl[e[p].to])cmin(top[o],dfn[e[p].to]);
	if(top[o]==dfn[o])
	{
		++pb;
		do
			bl[s[ts]]=pb,sum[pb]+=a[s[ts]];
		while(s[ts--]!=o);
	}
}
long long f[111111];
int main()
{
	int n=io::F(),m=io::F();
	for(int i=1;i<=n;++i)a[i]=io::F();
	for(int i=1;i<=m;++i)
	{
		int u=io::F(),v=io::F();
		insert(e,u,v,pe);
	}
	for(int i=1;i<=n;++i)
		if(!dfn[i])dfs(i); //tarjan 
	for(int i=1;i<=n;++i)
		for(int p=e[i].next;p;p=e[p].next)
			if(bl[i]!=bl[e[p].to])deg[bl[i]]++,insert(d,bl[e[p].to],bl[i],pd); //加强连通分量之间的边 
	for(int i=1;i<=pb;++i)
		if(deg[i]==0)q[tq++]=i,f[i]=sum[i];
	for(;hq!=tq;++hq)
		for(int p=d[q[hq]].next;p;p=d[p].next)
		{
			cmax(f[d[p].to],sum[d[p].to]+f[q[hq]]); //拓扑排序+DP 
			if(--deg[d[p].to]==0)q[tq++]=d[p].to;
		}
	long long ans=0;
	for(int i=1;i<=pb;++i)
		cmax(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}

