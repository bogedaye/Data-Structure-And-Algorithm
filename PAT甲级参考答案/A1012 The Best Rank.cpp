#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std; 

struct Student{
	int id;//存放6位整数的ID
	int grade[4];//存放4个分数
}stu[2010];

char course[4] = {'A', 'C', 'M', 'E'};//按优先级顺序，方便输出
int Rank[1000000][4] = {0};//Rank[id][0] ~ Rank[id][4]为4门课对应的排名
int now;//cmp函数中使用, 表示当前按now号分数排序stu的值 

bool cmp(Student stu1, Student stu2){//stu数组按now号分数递减排序 
	return stu1.grade[now] > stu2.grade[now];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	//读入分数 其中grade[0]~grade[3]分别代表A,C,M,E
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
	} 
//	for(int now = 0; now < 4; now++) 注意全局变量和局部变量 
	for(now = 0; now < 4; now++){//枚举A C M E中的一个 
		sort(stu, stu + n, cmp);//对所有考生按分数从大到小排序
		Rank[stu[0].id][now] = 1;
		for(int i = 1; i < n; i++){//对于剩下的考生 
			//若与前一位分数相同
			if(stu[i].grade[now] == stu[i - 1].grade[now]){
				Rank[stu[i].id][now] = Rank[stu[i-1].id][now];//则他们排名相同			
			}else{
				Rank[stu[i].id][now] = i + 1;//否则 设置正确的排名 
			} 
		} 
	} 
	int query;//查询的考生ID
	for(int i = 0; i < m; i++){
		scanf("%d", &query);
		if(Rank[query][0] == 0){//万一这个人都考0分呢 平均分不也是0分吗 有点奇怪 
			printf("N/A\n");
		}else{
			int k = 0;//选出Rank[query][0~3]中的最小的(rank值越小,排名越高)
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
