#include<cstdio>
#include<map>
using namespace std;

int main(){
	int n, m, color;
	scanf("%d%d",&n,&m);
	map<int, int>count;//数字与出现次数的map映射 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&color);
			if(count.find(color) != count.end())count[color]++;
			else count[color] = 1;
		}
	}
	int k = 0, MAX = 0;//最大数字及该数字出现次数 
	for(map<int, int>::iterator it = count.begin(); it != count.end(); it++){
		if(it -> second > MAX){
			k = it -> first;
			MAX = it -> second;
		}
	} 
	printf("%d\n",k);
	return 0;
} 
