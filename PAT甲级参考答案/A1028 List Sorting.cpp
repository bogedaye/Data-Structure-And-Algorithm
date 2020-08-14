#include<cstdio>
#include<algorithm> 
#include<string.h>
using namespace std;

const int maxn = 100010;
struct Student{
	int id;
	char name[10];
	int score;
}stu[maxn];

bool cmp1(Student stu1, Student stu2){
	return stu1.id < stu2.id;//按准考证号从小到大排序 
}

bool cmp2(Student stu1, Student stu2){
	int s = strcmp(stu1.name, stu2.name);
//	return s < 0;
	if(s != 0) return s < 0;
	else return stu1.id < stu2.id;	 
}

bool cmp3(Student stu1, Student stu2){
	if(stu1.score != stu2.score) return stu1.score < stu2.score;
	else return stu1.id < stu2.id; 
//	return stu1.score < stu2.score;
}

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	for(int i = 0; i < n; i++){
		scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
	}
	if(c == 1) sort(stu, stu + n, cmp1);
	else if(c == 2) sort(stu, stu + n, cmp2);
	else sort(stu, stu + n, cmp3);
	for(int i = 0; i < n; i++){
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	} 
	return 0;
} 
