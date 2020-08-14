#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

const int maxn = 40010;
const int maxc = 2510;
char name[maxn][5];//maxn个学生
vector<int> course[maxc];//course[i]存放第i门课的所有学生编号 

bool cmp(int a, int b){
	return strcmp(name[a], name[b]) < 0;
} 

int main(){
	int n, k, c, courseID;
	scanf("%d %d", &n, &k);//学生人数及课程数
	for(int i = 0; i < n; i++){
		scanf("%s %d", name[i], &c);//学生姓名及选课数
		for(int j = 0; j < c; j++){
			scanf("%d", &courseID);//选择的课程编号 
			course[courseID].push_back(i);//将学生i加入第courseID门课中 
		} 
	}
	for(int i = 1; i <= k; i++){
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for(int j = 0; j < course[i].size(); j++){
			printf("%s\n", name[course[i][j]]);
		}
	} 
	return 0;
}
