//�����Ŀ��û����� 
//�����û���� 
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 40010;//������
const int M = 26*26*26*10 + 1;//������ɢ�гɵ������Ͻ�
vector<int> selectCourse[M];//ÿ��ѧ��ѡ��Ŀγ̱��

int getID(char name[]){//hash���� ���ַ���nameת��������
	int id = 0;
	for(int i = 0;i < 3;i++){
		id = id * 26 + (name[i] - 'A');//??? 
	} 
	id = id * 10 + (name[3] - '0');//???
	return id;
} 

int main(){
	char name[5];
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 0;i < k;i++){
		int course,x;
		scanf("%d%d",&course,&x);
		for(int j = 0;j < x;j++){
			scanf("%s",name);//����һ��ѧ������ 
			int id = getID(name);//������ɢ��Ϊһ��������Ϊ��� 
			selectCourse[id].push_back(course);//���ÿγ̱�ż���ѧ��ѡ���� 
		}
	}
	for(int i = 0;i<n;i++){//n����ѯ 
		scanf("%s",name);//ѧ������ 
		int id = getID(name);//���ѧ����� 
		sort(selectCourse[id].begin(),selectCourse[id].end()); 
		printf("%s %d",name,selectCourse[id].size());//������ѡ���� 
		for(int j = 0;j < selectCourse[id].size();j++){
			printf(" %d",selectCourse[id][j]);//ѡ�α��
		}
		printf("\n"); 
	} 
	return 0;
}
