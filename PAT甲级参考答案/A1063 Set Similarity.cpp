#include<cstdio>
#include<set>
using namespace std;
const int N = 51;
set<int> st[N];
//the sets are numbered from 1 to N 
void compare(int a, int b){//比较集合a与集合b 
	//sameNum用来记录相同元素的个数 distinctNum用来记录不同元素的个数 
	int distinctNum = st[b].size(), sameNum = 0;
	//枚举集合a中的元素 判断其是否在集合b中出现过
	//如果出现, 说明找到一个相同元素 sameNum++
	//如果未出现, 说明找到一个新的不同的元素 distinctNum++
	//遍历完集合 计算sameNum * 100.0 / distinctNum
	//遍历集合a
	for(set<int>::iterator it = st[a].begin();it != st[a].end(); it++){
		if(st[b].find(*it) != st[b].end())sameNum++;//在st[b]中能找到该元素 
		else distinctNum++;//在st[a]中不能找到该元素 
	} 
	printf("%.1f%%\n", sameNum * 100.0 / distinctNum);
}

int main(){
	int n, k, queryNumber, value, index1, index2;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			scanf("%d",&value);
			st[i].insert(value);
		}
	}
	scanf("%d",&queryNumber);//queryNumber个查询 
	for(int i = 0; i < queryNumber; i++){
		scanf("%d%d", &index1, &index2);//欲对比的集合编号 
		//集合编号对应的两个集合
		compare(index1,index2);
	} 
	return 0;
} 
