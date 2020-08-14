#include <cmath>
#include <vector>
#include <stdio.h>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())
#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)
#define ALL(V) V.begin(),V.end()
#define pb push_back
#define mk make_pair
#define x first
#define y second

using namespace std;

typedef double db;
typedef long long LL;
typedef pair<int ,int> PII;
typedef pair<db ,db> cpx;
typedef vector<int> VI;
typedef vector<PII> VII;

inline int IN(){
	char c;Rin x=0;
	for(;oo<48 && c^'-' || c>57;);bool f=c=='-';if(f)oo;
	for(;c>47 && c<58;oo)x=(x<<3)+(x<<1)+c-48;if(f)x=-x;return x;
}

bool flag;

int n,m,M,mi,ma,he[33],jb[33],g[100010];
db ans,dis[33];
bool in[33];
struct Info{
	int u,v,w;
}ed[333];
struct Edge{
	int v;db w;int nxt;
}Ed[333];

inline bool spfa(){
	int l=0,r=1;
	for(in[g[l]=1]=1;l<r;){
		int u=g[l++];
		in[u]=0;
		for(int e=he[u];e;e=Ed[e].nxt){
			int v=Ed[e].v;
			db len=dis[u]+Ed[e].w;
			if(len<dis[v]){
				if(v==n){
					flag=1;
				}
				dis[v]=len;
				if(++jb[v]>n)return 1;
				if(v==n && dis[v]<0)return 1;
				if(!in[v])in[g[r++]=v]=1;
			}
		}
	}
	return 0;
}

int main(){
	freopen("nobel.in","r",stdin);
	freopen("nobel.out","w",stdout);
	n=IN();m=IN();
	mi=300;
	For(i,1,m){
		ed[i].u=IN();
		ed[i].v=IN();
		ed[i].w=IN();
		ma=max(ma,ed[i].w);
		mi=min(mi,ed[i].w);
	}
	ans=1e5;
	For(i,1,n)For(k,mi*i,ma*i)if(__gcd(i,k)==1){
		db ave=1.*k/i;
		db ll=0,rr=ans;
		rep(it,0,60){
			db mm=(ll+rr)*.5;
			M=0;
			For(u,1,n)he[u]=jb[u]=in[u]=0,dis[u]=1e9;dis[1]=0;
			For(j,1,m){
				Ed[++M]=(Edge){ed[j].v,(ed[j].w-ave)*(ed[j].w-ave)-mm,he[ed[j].u]};
				he[ed[j].u]=M;
			}
			if(spfa())rr=mm;else ll=mm;
		}
		ans=rr;
	}
	printf("%.10lf\n",sqrt(ans));
// never say goodbye
}
