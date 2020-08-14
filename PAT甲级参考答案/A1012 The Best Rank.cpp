#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std; 

struct Student{
	int id;//���6λ������ID
	int grade[4];//���4������
}stu[2010];

char course[4] = {'A', 'C', 'M', 'E'};//�����ȼ�˳�򣬷������
int Rank[1000000][4] = {0};//Rank[id][0] ~ Rank[id][4]Ϊ4�ſζ�Ӧ������
int now;//cmp������ʹ��, ��ʾ��ǰ��now�ŷ�������stu��ֵ 

bool cmp(Student stu1, Student stu2){//stu���鰴now�ŷ����ݼ����� 
	return stu1.grade[now] > stu2.grade[now];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	//������� ����grade[0]~grade[3]�ֱ����A,C,M,E
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
	} 
//	for(int now = 0; now < 4; now++) ע��ȫ�ֱ����;ֲ����� 
	for(now = 0; now < 4; now++){//ö��A C M E�е�һ�� 
		sort(stu, stu + n, cmp);//�����п����������Ӵ�С����
		Rank[stu[0].id][now] = 1;
		for(int i = 1; i < n; i++){//����ʣ�µĿ��� 
			//����ǰһλ������ͬ
			if(stu[i].grade[now] == stu[i - 1].grade[now]){
				Rank[stu[i].id][now] = Rank[stu[i-1].id][now];//������������ͬ			
			}else{
				Rank[stu[i].id][now] = i + 1;//���� ������ȷ������ 
			} 
		} 
	} 
	int query;//��ѯ�Ŀ���ID
	for(int i = 0; i < m; i++){
		scanf("%d", &query);
		if(Rank[query][0] == 0){//��һ����˶���0���� ƽ���ֲ�Ҳ��0���� �е���� 
			printf("N/A\n");
		}else{
			int k = 0;//ѡ��Rank[query][0~3]�е���С��(rankֵԽС,����Խ��)
			for(int j = 0; j < 4; j++){
				if(Rank[query][j] < Rank[query][k]){
					k = j;
				}
			} 
			printf("%d %c\n", Rank[query][k], course[k]);
		}
	} 
	return 0;
}
