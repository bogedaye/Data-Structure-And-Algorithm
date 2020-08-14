#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<ctime>
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
        ch=='-'?F=1:n=ch-'0';
        while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
        return F?n:-n;
    }
}
struct edge
{
    int to;
    int next;
}e[888888],t[1666666];
int pe=222222,pt=222222;
void insert(edge* e,int& pe,int a,int to)
{
    //if(e==t)printf("%d %d\n",a,to);
    e[pe]=(edge){to,e[a].next};
    e[a].next=pe++;
}
int s[666666],ts,low[222222],dfn[222222],dfc,bl[222222],pb;
int pno;
void dfs(int o,int fa)
{
    low[o]=dfn[o]=++dfc;
    s[++ts]=o;
    for(register int p=e[o].next;p;p=e[p].next)
        if(e[p].to!=fa)
            if(!dfn[e[p].to])
            {
                dfs(e[p].to,o);
                cmin(low[o],low[e[p].to]);
                if(low[e[p].to]>=dfn[o])
                {
                    ++pb;
                    ++pno;
					s[++ts]=o;
                    do
                    {
                        if(bl[s[ts]]!=pb)
                        {
                            bl[s[ts]]=pb;
                            insert(t,pt,pno,s[ts]);
                            insert(t,pt,s[ts],pno); // 给点双树加边 
                        }
                    }
                    while(s[ts--]!=e[p].to);
                }
            }
            else cmin(low[o],dfn[e[p].to]);
}
int n,m;
int vis[222222],pv,siz[222222],tot[222222];
int fa[222222];
void dfs2(int o,int fa)
{
    vis[o]=pv;
    if(o<=n)siz[o]=1;
    for(register int p=t[o].next;p;p=t[p].next)
        if(t[p].to!=fa)
        {
        	::fa[t[p].to]=o;
            dfs2(t[p].to,o);
            siz[o]+=siz[t[p].to]; //统计子树大小 
        }
}
int main()
{
    n=io::F(),m=io::F();
    for(register int i=1;i<=m;++i)
    {
        int x=io::F(),y=io::F();
        insert(e,pe,x,y);
        insert(e,pe,y,x);
    }
    pno=n;
    for(register int i=1;i<=n;++i)
        if(!dfn[i])
        {
            dfs(i,i);
            ++pb; //下面这段可以忽略 
            ++pno;
            do
            {
                if(bl[s[ts]]!=pb)
                {
                    bl[s[ts]]=pb;
                    insert(t,pt,pno,s[ts]);
                    insert(t,pt,s[ts],pno);
                }
            }
            while(--ts);
        }
    dfs2(1,1);
    for(int i=1;i<=n;++i)
    {
    	int sum=0;
    	long long sum2=0;
    	for(int p=t[i].next;p;p=t[p].next)
    	{
    		int s=fa[i]!=t[p].to?siz[t[p].to]:n-siz[i]; //外面的子树大小要特判 
    		sum+=s; //维护和 
    		sum2+=1ll*s*s; //维护平方和 
    	}
    	printf("%lld\n",n-1+(1ll*sum*sum-sum2)/2);
    }
    return 0;
}

