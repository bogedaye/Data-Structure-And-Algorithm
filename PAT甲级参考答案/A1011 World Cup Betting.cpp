#include<cstdio>
using namespace std;
 
char mp[3] = {'W', 'T', 'L'};

int main(){
	double profit = 1.0, tmp, value;
	int index;//记录每行最大数字的下标 
	for(int i = 0; i < 3; i++){
		tmp = 0.0;//寻找该行最大的值存于tmp 
		for(int j = 0; j < 3; j++){
			scanf("%lf", &value);
			if(value > tmp){
				tmp = value;
				index = j;
			} 
		}
		profit *= tmp; 
		printf("%c ",mp[index]);
	}
	printf("%.2f", (profit * 0.65 - 1) * 2);//输出最大收益 
	return 0;
} 
