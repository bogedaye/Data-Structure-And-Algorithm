#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
char c[110];
int main()
{
	srand(time(0));
	rep(i,26)c[i]=i+'a'-1;
	for(;;)
	{
		FILE *fin=fopen("1.in","w");
		int n=10;
		rep(i,n)fprintf(fin,"%d",i==1?rand()%9+1:rand()%10);fprintf(fin,"\n");
		int l=rand()%100,r=rand()%100;
		if(l>r)swap(l,r);
		fprintf(fin,"%d\n%d\n",l,r);
		fclose(fin);
		int x=system("./A <1.in >1.out");
		int y=system("./vio <1.in >2.out");
		if(x||y)return 0;
		if(system("diff 1.out 2.out"))return 0;
		puts("OK");
	}
	return 0;
}