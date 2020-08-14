#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
const int inf=-2000000001;
int X,Y,n,q,a[200010];
struct node
{
	long long lmax,rmax,mmax,sum;
	friend node operator +(const node&a,const node&b){return {max(a.lmax,a.sum+b.lmax),max(b.rmax,b.sum+a.rmax),max(max(a.mmax,b.mmax),a.rmax+b.lmax),a.sum+b.sum};}
	void print(){printf("%lld %lld %lld %lld\n",lmax,rmax,mmax,sum);}
};
struct SegmentTree
{
	node tree[1000010];
	void build(int p,int le,int ri,int c)
	{
		if(le==ri)
		{
			if(le==-1)tree[p]={max(0,c*inf),max(0,c*inf),max(0,c*inf),c*inf};
			else if(le==0)tree[p]={max(0,c*X),max(0,c*X),max(0,c*X),c*X};
			else tree[p]={max(0,c*a[le]),max(0,c*a[le]),max(0,c*a[le]),c*a[le]};
			return;
		}
		int mid=(le+ri)>>1;
		build(p<<1,le,mid,c);
		build(p<<1|1,mid+1,ri,c);
		tree[p]=tree[p<<1]+tree[p<<1|1];
	}
	void modify(int p,int le,int ri,int x,int y)
	{
		if(le==ri){tree[p]={max(0,y),max(0,y),max(0,y),y};return;}
		int mid=(le+ri)>>1;
		if(x<=mid)modify(p<<1,le,mid,x,y);
		else modify(p<<1|1,mid+1,ri,x,y);
		tree[p]=tree[p<<1]+tree[p<<1|1];
	}
	node getnode(int p,int le,int ri,int ll,int rr)
	{
		if(ll<=le&&ri<=rr)return tree[p];
		int mid=(le+ri)>>1;
		node ans={0,0,0,0};
		if(ll<=mid)ans=ans+getnode(p<<1,le,mid,ll,rr);
		if(rr>mid)ans=ans+getnode(p<<1|1,mid+1,ri,ll,rr);
		return ans;
	}
	int get(int p,int le,int ri,int S,node tmp)
	{
		if(le==ri)return le;
		int mid=(le+ri)>>1;
		if((tree[p<<1|1]+tmp).mmax>=S)return get(p<<1|1,mid+1,ri,S,tmp);
		else return get(p<<1,le,mid,S,tree[p<<1|1]+tmp);
	}
}MaxT,MinT;
int query()
{
	int x=MaxT.get(1,-1,n,X+Y,{0,0,0,0}),y=MinT.get(1,-1,n,X+Y,{0,0,0,0});
	node ans=x>y?MaxT.getnode(1,-1,n,x,n):MinT.getnode(1,-1,n,y,n);
	return x>y?X+Y+(ans.sum-ans.mmax):-(ans.sum-ans.mmax);
}
int main()
{
	scanf("%d",&n);
	scanf("%d%d",&X,&Y);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)if(i%2==0)a[i]=-a[i];
	MaxT.build(1,-1,n,1);
	MinT.build(1,-1,n,-1);
	scanf("%d",&q);
	rep(i,q)
	{
		int t,s,v;
		scanf("%d",&t);
		if(t==1){scanf("%d",&X);MaxT.modify(1,-1,n,0,X);MinT.modify(1,-1,n,0,-X);}
		else if(t==2)scanf("%d",&Y);
		else
		{
			scanf("%d%d",&s,&v);
			MaxT.modify(1,-1,n,s,(s%2?1:-1)*v);
			MinT.modify(1,-1,n,s,(s%2?-1:1)*v);
		}
		printf("%d\n",query());
	}
	return 0;
}