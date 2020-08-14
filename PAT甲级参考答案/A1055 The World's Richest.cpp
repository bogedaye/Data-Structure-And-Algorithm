#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
const int maxn = 100010;
int Age[maxn] = {0};

struct Person{
	char name[10];
	int age, networth;
}person[maxn], valid[maxn];//所有人 在各自年龄中财富值在100名以内的人 
 
bool cmp(Person a, Person b){
	if(a.networth != b.networth) return a.networth > b.networth;
	else if(a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);//总人数 查询次数
	for(int i = 0; i < n; i++){
		scanf("%s %d %d", person[i].name, &person[i].age, &person[i].networth);
	}
	sort(person, person + n, cmp);
	int validNum = 0;//存放到valid数组的人数
	for(int i = 0; i < n; i++){
		if(Age[person[i].age] < 100){
			Age[person[i].age]++;
			valid[validNum++] = person[i];
		}
	} 
	int m, ageL, ageR;
	for(int i = 1; i <= k; i++){
		scanf("%d%d%d", &m, &ageL, &ageR);//前M人 年龄区间[ageL,ageR]
		printf("Case #%d:\n", i);
		int printNum = 0;//已输出的人数
		for(int j = 0; j < validNum && printNum < m; j++){
			if(valid[j].age >= ageL && valid[j].age <= ageR){
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].networth);
				printNum++;
			}
		} 
		if(printNum == 0){
			printf("None\n");
		}
	} 
	return 0;
}
