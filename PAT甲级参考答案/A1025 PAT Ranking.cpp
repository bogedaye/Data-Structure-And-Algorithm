#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

struct Student{
	char id[20];//准考证号 
	int score;//分数
	int location_number;//考场号
	int local_rank;//考场内排名 
}stu[30010];

bool cmp(Student stu1, Student stu2){
	if(stu1.score != stu2.score) return stu1.score > stu2.score;//先按分数从高到低排序 
	else return strcmp(stu1.id, stu2.id) < 0;//若分数相同 则按准考证号从小到大排序 
} 

int main(){
	int n, k, num = 0;//num为总考生数
	scanf("%d", &n);//n为考场数
	for(int i = 1; i <= n; i++){
		scanf("%d", &k);//k为该考场内的人数
		//先初始化每个考场的考生的基本信息 
		for(int j = 0; j < k; j++){
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;//该考生的考场号为i 
			num++;//总考生数加1 
		} 
		//对每个考场的考生排序 
		sort(stu + num - k, stu + num, cmp);
		stu[num - k].local_rank = 1;//将该考场第一名的local_rank设为1
		for(int j = num - k + 1; j < num; j++){//对考场其他学生 
			if(stu[j].score = stu[j-1].score){//如果与前一位考生得分 
				stu[j].local_rank = stu[j - 1].local_rank; 
			} else{//如果与前一位考生得分不同 local_rank为该考生前的人数 
				stu[j].local_rank = j + 1 - (num - k); 
			}
		} 
	} 
	printf("%d\n", num);
	sort(stu, stu + num, cmp);//将所有考生排序 
	int final_rank = 1;//当前考生的排名 
	for(int i = 0; i < num; i++){
		if(i > 0 && stu[i].score != stu[i - 1].score){
			final_rank = i + 1;
		}
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", final_rank, stu[i].location_number, stu[i].local_rank);
	} 	
	return 0;
} 
