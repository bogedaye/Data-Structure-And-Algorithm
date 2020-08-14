#include<cstdio>
const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;

//upper_bound函数返回在[L, R)内第一个大于x的位置
//什么时候是在[L,R]内 什么时候是在[L,R)内？？？ 
int upper_bound(int L, int R, int x){
	int left = L, right = R, mid;
	while(left < right){
		mid = (left + right) / 2;
		if(sum[mid] > x){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return left;
}
 
int main(){
	scanf("%d %d", &n, &S);//元素个数 和值S 
	sum[0]= 0; 
	for(int i = 1; i <= n; i++){
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	for(int i = 1; i <= n; i++){//枚举左端点 
		int j = upper_bound(i, n + 1, sum[i - 1] + S);//求右端点 
		if(sum[j - 1] - sum[i - 1] == S){//查找成功(注意是j-1而不是j) 
			nearS = S;//最接近S的值就是S 
			break; 
		}else if(j <= n && sum[j] - sum[i - 1] < nearS){
			//存在大于S的解并小于nearS
			nearS = sum[j] - sum[i - 1];//更新当前nearS 
		} 
	}
	for(int i = 1; i <= n; i++){
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);
		if(sum[j - 1] - sum[i - 1] == nearS){//查找成功 
			printf("%d-%d\n", i, j - 1);//输出左端点和右端点(注意是j - 1而不是j) 
		}
	}
	return 0;
} 
