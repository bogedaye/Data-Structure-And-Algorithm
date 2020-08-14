#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1010;
int father[N];//��Ÿ��׽��
int isRoot[N] = {0};//��¼ÿ������Ƿ���Ϊĳ�����ϵĸ����
int course[N] = {0};

void init(int n){
	for(int i = 1; i <= n; i++){
		father[i] = i;
		isRoot[i] = false;
	}	
}

int findFather(int x){//����x���ڼ��ϵĸ���� 
	int a = x;
	while(x != father[x]){
		x = father[x];
	} 
	//·��ѹ��
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	} 
	return x;
}

void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n, k, h;
	scanf("%d", &n);
	init(n);
	for(int i = 1; i <= n; i++){//��ÿ���� 
		scanf("%d:", &k);//����� 
		for(int j = 0; j < k; j++){//��ÿ��� 
			scanf("%d", &h);//����i����ϲ���Ļh
			if(course[h] == 0){//����h��һ������ϲ�� 
				course[h] = i;//��iϲ���h 
			} 
			Union(i, findFather(course[h]));
		}
	} 
	for(int i = 1; i <= n; i++){
		isRoot[findFather(i)]++;//i�ĸ������findFather(i) ������1 
	}
	int ans = 0;//��¼������Ŀ
	for(int i = 1; i <= n; i++){
		if(isRoot[i] != 0){
			ans++;
		}
	} 
	printf("%d\n", ans);//��¼���ϸ��� 
	sort(isRoot + 1, isRoot + n + 1, cmp);
	for(int i = 1; i <= ans ; i++){
		printf("%d", isRoot[i]);
		if(i < ans) printf(" ");
	} 
	return 0;
}
