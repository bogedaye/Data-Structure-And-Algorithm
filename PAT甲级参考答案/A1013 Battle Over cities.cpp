#include<cstdio>
#include<vector>
#include<cstring> 
using namespace std;

const int N = 1010;
vector<int> G[N];//邻接表 
bool vis[N];//标记顶点i是否已被访问 
int n, m, k;
int currentPoint;//当前需要删除的顶点编号 

//dfs遍历顶点v所在的连通块 
void dfs(int v){
	if(v == currentPoint) return;//当遍历到欲删除的顶点v时 返回
	vis[v] = true;//标记顶点v已被访问
	for(int i = 0; i < G[v].size(); i++){//遍历v的所有邻接点 
		if(vis[G[v][i]] == false){
			dfs(G[v][i]);
		}
	} 
} 
 
int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);//边a->b 
		G[b].push_back(a);//边b->a 
	}	
	for(int query = 0; query < k; query++){//k次查询 
		scanf("%d", &currentPoint);//欲删除的顶点编号
		memset(vis, false, sizeof(vis));//初始化vis数组为false 
		int block = 0;
		for(int i = 1; i <= n; i++){//枚举每个顶点 
			if(i != currentPoint && vis[i] == false){//如果未被删除且未被访问 
				dfs(i);//遍历顶点i所在的连通块
				block++;//连通块个数加1 
			} 
		}
		printf("%d\n", block - 1);
	} 
	return 0;
}
