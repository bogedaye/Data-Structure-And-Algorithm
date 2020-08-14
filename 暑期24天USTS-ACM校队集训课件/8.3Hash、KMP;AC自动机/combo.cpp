#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
namespace io
{
	int F()
	{
		int n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
	long long G()
	{
		long long n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
}
int to[255];
char s[333];
int sc;
struct trie
{
	int sc;
	trie* next[4];
	trie* fa;
}t[1111],*pt=t+1,*q[1111];
int hq,tq;
void insert(trie* d,trie* &pd,char* s)
{
	if(*s==0)
	{
		d->sc+=sc;
		return;
	}
	if(!d->next[to[*s]])d->next[to[*s]]=pd++;
	insert(d->next[to[*s]],pd,s+1);
}
void ext(trie* d)
{
	trie* tmp;
	for(q[hq=0]=d,tq=1;hq!=tq;++hq)
		for(register int i=0;i<=3;++i)
			if(tmp=q[hq]->next[i])
			{
				register trie* p;
				for(p=q[hq]->fa;p&&!p->next[i];p=p->fa);
				if(p)tmp->fa=p->next[i];
					else tmp->fa=d;
				q[tq++]=q[hq]->next[i];
			}
	d->fa=d;
	for(register int j=0;j<=3;++j)
		if(!d->next[j])d->next[j]=d;
	for(register int i=1;i<tq;++i)
	{
		for(register int j=0;j<=3;++j)
			if(!q[i]->next[j])q[i]->next[j]=q[i]->fa->next[j];
		q[i]->sc+=q[i]->fa->sc;
	}
}
int n,m;
long long f[1111][1111];
int main()
{
	to['A']=0,to['B']=1,to['X']=2,to['Y']=3;
	n=io::F(),m=io::F();
	for(int i=1;i<=m;++i)
	{
		scanf("%s",s);
		sc=io::F();
		insert(t,pt,s);
	}
	ext(t);
	memset(f,192,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<pt-t;++j)
			if(f[i][j]>=0)
				for(int k=0;k<=3;++k)
					cmax(f[i+1][t[j].next[k]-t],f[i][j]+t[j].next[k]->sc);
	long long ans=0;
	for(int j=0;j<pt-t;++j)
		cmax(ans,f[n][j]);
	printf("%lld\n",ans);
	return 0;
}

