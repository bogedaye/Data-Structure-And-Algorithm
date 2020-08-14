#include<cstdio>
#include<algorithm>
#include<string.h> 
using namespace std;

struct Student{
	char id[10];//׼��֤�� 
	int de, cai, sum;//�·֡��ŷּ��ܷ� 
	int flag;//������� ��1��-��5�� 
}stu[100010];

bool cmp(Student stu1, Student stu2){
	if(stu1.flag != stu2.flag) return stu1.flag < stu2.flag;//С�������ǰ
	else if(stu1.sum != stu2.sum) return stu1.sum > stu2.sum;//�ָܷߵ���ǰ
	else if(stu1.de != stu2.de) return stu1.de > stu2.de;//�·ָߵ���ǰ 
	else return strcmp(stu1.id, stu2.id) < 0;//׼��֤��С����ǰ 
}

int main(){
	int n, L, H;
	scanf("%d %d %d", &n, &L, &H);
	int cnt = n;//mΪ��������
	for(int i = 0; i < n; i++){
		scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;//�����ܷ�
		if(stu[i].de < L || stu[i].cai < L){
			stu[i].flag = 5;
			cnt--;
		} 
		else if(stu[i].de >= H && stu[i].cai >= H) stu[i].flag = 1;
		else if(stu[i].de >= H && stu[i].cai < H) stu[i].flag = 2;
		else if(stu[i].de < H && stu[i].cai < H && stu[i].de >= stu[i].cai) stu[i].flag = 3;
		else stu[i].flag = 4;	 
	}
	sort(stu, stu + n, cmp);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++){
		printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	} 
	return 0;
}
