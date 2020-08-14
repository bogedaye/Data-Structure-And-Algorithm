#include<cstdio>
#include<algorithm>
#include<string.h> 
using namespace std;

struct Student{
	char id[10];//准考证号 
	int de, cai, sum;//德分、才分及总分 
	int flag;//考生类别 第1类-第5类 
}stu[100010];

bool cmp(Student stu1, Student stu2){
	if(stu1.flag != stu2.flag) return stu1.flag < stu2.flag;//小的类别在前
	else if(stu1.sum != stu2.sum) return stu1.sum > stu2.sum;//总分高的在前
	else if(stu1.de != stu2.de) return stu1.de > stu2.de;//德分高的在前 
	else return strcmp(stu1.id, stu2.id) < 0;//准考证号小的在前 
}

int main(){
	int n, L, H;
	scanf("%d %d %d", &n, &L, &H);
	int cnt = n;//m为及格人数
	for(int i = 0; i < n; i++){
		scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;//计算总分
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
