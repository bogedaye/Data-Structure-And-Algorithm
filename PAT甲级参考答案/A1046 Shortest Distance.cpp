#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
//以dis[i]表示1号结点按顺时针方向到达"i号结点顺时针方向的下一个结点"的距离 
//A[i]存放i号与i+1号顶点的距离 
int dis[maxn], A[maxn]; 
int main(){
	int sum = 0, query, n, left, right;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&A[i]);
		sum += A[i];//累加sum 
		dis[i] = sum;//预处理dis数组 
	}	
	scanf("%d", &query);
	for(int i = 0; i < query; i++){//query个查询 
		scanf("%d%d",&left,&right);//left->right
		if(left > right) swap(left, right);//left > right时交换
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp,sum - temp)); 
	}
	return 0; 
} 
