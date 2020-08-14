#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
queue<int> que;
int a[1<<21],dis[1<<21],n,m,T,ans;
char s[22];
bool exist[1<<21],vis[1<<21];
void work(int x)
{
	dis[x]=0;
	que.push(x);
	for(;!que.empty();)
	{
		int u=que.front();que.pop();
		if(!vis[u]&&exist[u])
		{
			q.push({dis[u],u});
		}
		for(int i=0;i<n;i++)
		{
			int v=u^(1<<i);
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				que.push(v);
			}
		}
	}
}
int main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&n,&m);
		memset(exist,0,sizeof(exist));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)
		{
			scanf("%s",s);
			a[i]=0;
			for(int j=0;j<n;j++)
			{
				a[i]=(a[i]<<1)|(s[j]=='R');
			}
			exist[a[i]]=1;
		}
		for(int i=0;i<(1<<n);i++)
		{
			dis[i]=50;
		};
		q.push({0,a[1]});
		ans=0;
		for(;!q.empty();)
		{
			pair<int,int> u=q.top();q.pop();
			if(vis[u.second])
			{
				continue;
			}
			ans+=u.first;
			vis[u.second]=1;
			work(u.second);
		}
		printf("%d\n",ans);
	}
	return 0;
}