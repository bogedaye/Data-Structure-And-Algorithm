//============================================================================
// Author       : Sun YaoFeng
//============================================================================

//#pragma 	comment(linker, "/STACK:100240000,100240000")
//#include	<cstdio>
//#include	<cstdlib>
//#include	<cstring>
//#include	<algorithm>

#include	<bits/stdc++.h>

using	namespace	std;

#define DB		long double
#define	lf		else if
#define I64		long long
#define	Rd()	(rand()<<15|rand())
#define For(i,a,b)	for(int i=a,lim=b;i<=lim;i++)
#define Rep(i,a,b)	for(int i=a,lim=b;i>=lim;i--)

#define	fi	first
#define se	second
#define MK	make_pair
#define PA	pair<int, int>

//#define	min(a,b)	((a)<(b)?(a):(b))
//#define	max(a,b)	((a)<(b)?(b):(a))

#define	CH	(ch=getchar())
int		IN()	{
		int x= 0, f= 0, ch;
		for	(; CH < '0' || ch > '9';)	f= (ch == '-');
		for	(; ch >= '0' && ch <= '9'; CH)	x= x*10 + ch -'0';
		return	f? -x : x;
}

#define n	105
#define m	205

int		N, D, st[n], Max[n];

DB		F[n][m][m], G[2][m][m][m];

struct	Lin{
		int v, next;
}E[m];

void	Link(int u, int v){
		E[++ D]= (Lin){v, st[u]};	st[u]= D;
		E[++ D]= (Lin){u, st[v]};	st[v]= D;
}

void	DFS(int u, int f){
		for (int i= st[u], v; i; i= E[i].next)
			if	((v= E[i].v) != f)	DFS(v, u);
		
		For(i, 0, 2*N)	G[0][0][0][i]= 1.;
		
		int p= 0, q= 1;
		for (int i= st[u], v; i; i= E[i].next)
		if	((v= E[i].v) != f)	{
			For(x, 0, Max[v])	For(y, 1, 2*N)	F[v][x][y]+= F[v][x][y-1];
			
			p^= 1;
			q^= 1;
			
			For(x, 0, Max[u])	For(y, 0, x)	For(z, 0, 2*N){
				DB val= G[q][x][y][z];
				G[q][x][y][z]= 0;
				
				For(l, 0, Max[v])	For(t, 1, 2)	{
					DB	tmp= F[v][l][z] * .5;
					
					if	(l+t > x)	G[p][l+t][x][z]+= val*tmp;
					lf	(l+t > y)	G[p][x][l+t][z]+= val*tmp;
						else	G[p][x][y][z]+= val*tmp;
				}
			}
			
			Max[u]= max(Max[u], Max[v] + 2);
		}
		
		For(x, 0, Max[u])	For(y, 0, x)	Rep(z, 2*N, 0){
			DB	t= G[p][x][y][z] - (z ? G[p][x][y][z-1] : 0);
			G[p][x][y][z]= 0;
	
			if	(x+y <= 2*N)	F[u][x][max(x+y, z)]+= t;
		}
}

class	DiameterOfRandomTree{
	public:
		double	getExpectation(){
			N= IN();
			For(i, 2, N)	Link(IN(), IN());
			
			DFS(1, 0);
			
			DB	Ans= 0;
			For(i, 0, Max[1])	For(j, 0, 2*N)	Ans+= j*F[1][i][j];
			
			return	Ans;
		}
}GTW;

int		main(int argc, char* argv[]){
		freopen("gtree.in", "r", stdin);
		freopen("gtree.out", "w", stdout);
	
		printf("%.12lf\n", GTW.getExpectation());
		
		return	0;
}