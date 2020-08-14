#include<stdio.h>
#include<algorithm>
#include<map>
//#define read(x) scanf("%d",&x)
#define N 500005
#define M 1000005
using namespace std;
struct data{
	int x,y,w,id;
	int operator < (const data &b)const{return w<b.w;}
}a[M];map<long long,bool>Hash;
int Go[N<<1],Next[N<<1],End[N],pre[N],deep[N],index[N];
int f[N],mark[M],Q,n,m,i,id,cnt,T;long long ans,ret[M];
int get(int u){return f[u]==u?u:f[u]=get(f[u]);}
void add(int u,int v){Go[++cnt]=v;Next[cnt]=End[u];End[u]=cnt;}
void DFS(int x){
	for (int i=End[x];i;i=Next[i]){
		int id=Go[i];
		int y=a[id].x==x?a[id].y:a[id].x;
		if (y==pre[x]) continue;
		pre[y]=x;index[y]=id;
		deep[y]=deep[x]+1;DFS(y);
  }
}
void MST(){
	int c=n;long long ans=0;
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++){
		int u=get(a[i].x),v=get(a[i].y);
		if (u==v) continue;f[u]=v;
		mark[i]=1;ans+=a[i].w;
		add(a[i].x,i);
		add(a[i].y,i);
		if ((--c)==1) break;
  }if (c>1) return;DFS(1);
  for (int i=1;i<=n;i++) f[i]=i;
  for (int i=1;i<=m;i++)
		if (!mark[i]){
			int u=get(a[i].x),v=get(a[i].y);
			while (u!=v){
				if (deep[u]<deep[v]) swap(u,v);
				ret[a[index[u]].id]=ans-a[index[u]].w+a[i].w;
				f[u]=pre[u];u=get(u);
		  }ret[a[i].id]=ans;
	  }
}
inline char nc(){
  static char buf[100000],*p1=buf+100000,*pend=buf+100000;
  if (p1==pend) p1=buf,pend=buf+fread(buf,1,100000,stdin);
  return *p1++;
}
void read(int &x){
  char ch=nc();x=0;
  for (;ch<'0';ch=nc());
  for (;ch>='0';ch=nc()) x=x*10+ch-'0';
}
void Print(long long x){
	static int a[20];*a=0;
	for (;x;x/=10) a[++*a]=x%10;
	for (;*a;--*a) putchar(a[*a]+'0');
}
int main(){
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	read(n);read(m);read(T);
	for (i=1;i<=m;i++)
		read(a[i].x),read(a[i].y),read(a[i].w),a[i].id=i;
	sort(a+1,a+m+1);
	for (i=1;i<=m;i++) ret[i]=-1;
	MST();read(Q);
	while (Q--){
		read(id);
		id=(id-1+1ll*ans*T)%m+1;
		if (ret[id]==-1) puts("Not connected");
	  else Print(ret[id]),ans=ret[id],puts("");
  }//fprintf(stderr,"%d\n",Hash.size());
}
