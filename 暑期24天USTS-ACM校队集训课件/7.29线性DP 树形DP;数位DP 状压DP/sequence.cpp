#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int p=1000000007;

int k,m,n;

inline void subtask1()
{
	bool b[3000];
	memset(b,false,sizeof(b));
	for (int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		for (int j=l;j<=r;j++)
			b[j]=true;
	}
	int s=1;
	for (int i=1;i<=n;i++)
		if (! b[i])
			s=s*2%p;
	printf("%d",s);
	return;
}

inline void subtask2()
{
	int h[3000],r[3000];
	memset(h,0,sizeof(h));
	memset(r,0,sizeof(r));
	for (int i=1;i<=n;i++)
		r[i]=i+1;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for (int j=x;j<=y;j++)
			r[j]=max(r[j],y+1);
	}
	h[1]=1;
	for (int i=1;i<=n;i++)
	{
		h[i+1]=(h[i+1]+h[i])%p;
		h[r[i]]=(h[r[i]]+h[i])%p;
	}
	printf("%d",(h[n+1])%p);
	return;
}

inline void subtask3()
{
	int h[3000][3000],r[3000];
	memset(h,0,sizeof(h));
	for (int i=1;i<=n;i++)
		r[i]=i+1;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for (int j=x;j<=y;j++)
			r[j]=max(r[j],y+1);
	}
	int s=0;
	h[0][1]=1;
	for (int i=0;i<=n;i++)
	{
		for (int j=i+1;j<=n+1;j++)
		{
			h[i][j]=(h[i][j]+h[i][j-1])%p;
			h[j][max(r[i],j+1)]=(h[j][max(r[i],j+1)]+h[i][j])%p;
		}
		s=(s+h[i][n+1])%p;
	}
	printf("%d",s);
	return;
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if (k==0)
		subtask1();
	if (k==1)
		subtask2();
	if (k==2)
		subtask3();
	return 0;
}
