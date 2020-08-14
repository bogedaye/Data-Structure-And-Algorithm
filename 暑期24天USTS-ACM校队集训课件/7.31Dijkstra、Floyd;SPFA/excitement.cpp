#include <cstdio>
#include <algorithm>

using namespace std;

int edge[500000],next[500000],dist[500000],first[200000];
int b[200000],d[200000],g[10000000],h[10000000],p[200000],r[200000];
int i,k,m,n,x,y,z,head,tail,sum_edge;

int main()
{
	freopen("excitement.in","r",stdin);
	freopen("excitement.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=n;i++)
		scanf("%d",&r[i]);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		sum_edge++,edge[sum_edge]=y,next[sum_edge]=first[x],dist[sum_edge]=z,first[x]=sum_edge;
		sum_edge++,edge[sum_edge]=x,next[sum_edge]=first[y],dist[sum_edge]=z,first[y]=sum_edge;
	}
	d[1]=p[1]=k;
	tail++,g[tail]=1,h[tail]=0;
	for (head=1;head<=tail;head++)
	{
		if (g[head]==n)
		{
			printf("%d\n",h[head]);
			return 0;
		}
		if (h[head]!=h[head-1])
			for (i=head;i<=tail;i++)
				d[g[i]]=p[g[i]],b[g[i]]=0;
		for (i=first[g[head]];i!=0;i=next[i])
			if ((d[g[head]]>dist[i]) && (min(d[g[head]]-dist[i]+r[edge[i]],k)>p[edge[i]]))
			{
				p[edge[i]]=min(d[g[head]]-dist[i]+r[edge[i]],k);
				if (! b[edge[i]])
					tail++,g[tail]=edge[i],h[tail]=h[head]+1,b[edge[i]]=1;
			}
	}
	printf("-1\n");
	return 0;
}
