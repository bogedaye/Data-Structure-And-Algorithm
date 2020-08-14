//这道题目还没搞清楚 
//题意就没看懂 
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 40010;//总人数
const int M = 26*26*26*10 + 1;//由姓名散列成的数字上界
vector<int> selectCourse[M];//每个学生选择的课程编号

int getID(char name[]){//hash函数 将字符串name转换成数字
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
			scanf("%s",name);//输入一个学生姓名 
			int id = getID(name);//将姓名散列为一个整数作为编号 
			selectCourse[id].push_back(course);//将该课程编号加入学生选择中 
		}
	}
	for(int i = 0;i<n;i++){//n个查询 
		scanf("%s",name);//学生姓名 
		int id = getID(name);//获得学生编号 
		sort(selectCourse[id].begin(),selectCourse[id].end()); 
		printf("%s %d",name,selectCourse[id].size());//姓名、选课数 
		for(int j = 0;j < selectCourse[id].size();j++){
			printf(" %d",selectCourse[id][j]);//选课编号
		}
		printf("\n"); 
	} 
	return 0;
}
