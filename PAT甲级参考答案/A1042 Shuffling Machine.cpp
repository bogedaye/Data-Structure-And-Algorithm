#include<cstdio>

const int n = 54;
int start[n+1], end[n+1], next[n+1];//next数组存放每个位置上的牌在操作之后的位置 
char mp[5] = {'S', 'H', 'C', 'D', 'J'};

int main(){
	int k;
	scanf("%d",&k);//the number of repeat times
	for(int i = 1; i <= n; i++){
		start[i] = i//初始化牌的编号 
		//start[1] = 1, start[2] = 2,start[3] = 3... 
	} 
	for(int i = 1; i <= n; i++){
		scanf("%d",&next[i]);//输入每个位置上的牌在操作后的位置 
		//next[1] = 5, next[2] = 17, next[3] = 18, next[4] = 19... 
	} 
	for(int step = 0; step < k; step++){//执行k次操作 
		for(int i = 1; i <= n; i++){
			end[next[i]] = start[i];//end[]数组用来存放执行后的牌的编号顺序 
		//比如step为0时 end[next[1]] = start[1] = 1
		//next[1] = 5即是把第1个位置上的数移到第5个位置上
		//end[5] = 1  
		}
		for(int i = 1; i <= n; i++){
			start[i] = end[i];
			//把end数组赋值给start数组以供下一次使用
			//因为要k次这样做 
			//执行k轮操作后 数组start[]中就存放了最终的顺序 
		}
	} 
	for(int i = 1; i <= n; i++){
		if(i != 1)printf(" ");
		start[i]--;//需要的 
		printf("%c%d",mp[start[i] / 13],mp[start[i] % 13]); 
		//mp[start[1]/13] = mp[]  
	} 
	return 0;
} 
