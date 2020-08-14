#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

const int maxn = 40010;
const int maxc = 2510;
char name[maxn][5];//maxn��ѧ��
vector<int> course[maxc];//course[i]��ŵ�i�ſε�����ѧ����� 

bool cmp(int a, int b){
	return strcmp(name[a], name[b]) < 0;
} 

int main(){
	int n, k, c, courseID;
	scanf("%d %d", &n, &k);//ѧ���������γ���
	for(int i = 0; i < n; i++){
		scanf("%s %d", name[i], &c);//ѧ��������ѡ����
		for(int j = 0; j < c; j++){
			scanf("%d", &courseID);//ѡ��Ŀγ̱�� 
			course[courseID].push_back(i);//��ѧ��i�����courseID�ſ��� 
		} 
	}
	for(int i = 1; i <= k; i++){
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for(int j = 0; j < course[i].size(); j++){
			printf("%s\n", name[course[i][j]]);
		}
	} 
	return 0;
}
