#include<cstdio>
#include<vector>
#include<cstring> 
using namespace std;

const int N = 1010;
vector<int> G[N];//�ڽӱ� 
bool vis[N];//��Ƕ���i�Ƿ��ѱ����� 
int n, m, k;
int currentPoint;//��ǰ��Ҫɾ���Ķ����� 

//dfs��������v���ڵ���ͨ�� 
void dfs(int v){
	if(v == currentPoint) return;//����������ɾ���Ķ���vʱ ����
	vis[v] = true;//��Ƕ���v�ѱ�����
	for(int i = 0; i < G[v].size(); i++){//����v�������ڽӵ� 
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
		G[a].push_back(b);//��a->b 
		G[b].push_back(a);//��b->a 
	}	
	for(int query = 0; query < k; query++){//k�β�ѯ 
		scanf("%d", &currentPoint);//��ɾ���Ķ�����
		memset(vis, false, sizeof(vis));//��ʼ��vis����Ϊfalse 
		int block = 0;
		for(int i = 1; i <= n; i++){//ö��ÿ������ 
			if(i != currentPoint && vis[i] == false){//���δ��ɾ����δ������ 
				dfs(i);//��������i���ڵ���ͨ��
				block++;//��ͨ�������1 
			} 
		}
		printf("%d\n", block - 1);
	} 
	return 0;
}
