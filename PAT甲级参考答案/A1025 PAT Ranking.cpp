#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

struct Student{
	char id[20];//׼��֤�� 
	int score;//����
	int location_number;//������
	int local_rank;//���������� 
}stu[30010];

bool cmp(Student stu1, Student stu2){
	if(stu1.score != stu2.score) return stu1.score > stu2.score;//�Ȱ������Ӹߵ������� 
	else return strcmp(stu1.id, stu2.id) < 0;//��������ͬ ��׼��֤�Ŵ�С�������� 
} 

int main(){
	int n, k, num = 0;//numΪ�ܿ�����
	scanf("%d", &n);//nΪ������
	for(int i = 1; i <= n; i++){
		scanf("%d", &k);//kΪ�ÿ����ڵ�����
		//�ȳ�ʼ��ÿ�������Ŀ����Ļ�����Ϣ 
		for(int j = 0; j < k; j++){
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;//�ÿ����Ŀ�����Ϊi 
			num++;//�ܿ�������1 
		} 
		//��ÿ�������Ŀ������� 
		sort(stu + num - k, stu + num, cmp);
		stu[num - k].local_rank = 1;//���ÿ�����һ����local_rank��Ϊ1
		for(int j = num - k + 1; j < num; j++){//�Կ�������ѧ�� 
			if(stu[j].score = stu[j-1].score){//�����ǰһλ�����÷� 
				stu[j].local_rank = stu[j - 1].local_rank; 
			} else{//�����ǰһλ�����÷ֲ�ͬ local_rankΪ�ÿ���ǰ������ 
				stu[j].local_rank = j + 1 - (num - k); 
			}
		} 
	} 
	printf("%d\n", num);
	sort(stu, stu + num, cmp);//�����п������� 
	int final_rank = 1;//��ǰ���������� 
	for(int i = 0; i < num; i++){
		if(i > 0 && stu[i].score != stu[i - 1].score){
			final_rank = i + 1;
		}
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", final_rank, stu[i].location_number, stu[i].local_rank);
	} 	
	return 0;
} 
