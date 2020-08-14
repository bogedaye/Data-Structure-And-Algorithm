#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std; 

typedef long long LL;
LL inf = (1LL << 63) - 1;//long long的最大值2^63 - 1 
LL Map[256];//'0'-'9', 'a'-'z'与0 ~ 35对应 
 
void init(){
	for(char c = '0'; c <= '9'; c++){
		Map[c] = c - '0';
	}
	for(char c = 'a'; c <= 'z'; c++){
		Map[c] = c - 'a' + 10;
	}
}

LL convertToTen(char a[], LL radix, LL t){//将a转换为十进制 t为上界 
	LL ans = 0;
	int len = strlen(a);
	for(int i = 0; i < len; i++){
		ans = ans * radix + Map[a[i]];
		if(ans < 0 || ans > t) return -1;
	}
	return ans;
}

//这个函数没懂是干嘛用的 
//找到N2中数位最大的位加1  
int findLargestDigit(char N2[]){//求最大的数位 
	int ans = -1, len = strlen(N2);
	for(int i = 0; i < len; i++){
		if(Map[N2[i]] > ans){//？？？ 
			ans = Map[N2[i]];//？？？ 
		}
	}
	return ans + 1;//最大的数位为ans 说明进制数的底线是ans + 1 
}

int cmp(char N2[], LL radix, LL t){//N2的十进制数与t比较 
	int len = strlen(N2);
	LL num = convertToTen(N2, radix, t);//将N2转换成十进制 
	if(num < 0) return 1;//溢出 肯定是N2 > t
	
	if(t > num) return -1;//t较大 返回-1
	else if(t == num) return 0;//相等 返回0
	else return 1;//num较大 返回1 
}

LL binarySearch(char N2[], LL left, LL right, LL t){
	LL mid;
	while(left <= right){
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);
		if(flag == 0) return mid;
		else if(flag == -1) left = mid + 1;
		else right = mid - 1; 
	}
	return -1;//解不存在 
} 

int main(){
	char N1[20], N2[20], temp[20];
	int tag, radix;
	scanf("%s %s %d %d", N1, N2, &tag, &radix);
	if(tag == 2){
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp); 
	}	
	//将N1从radix进制转换为十进制
	LL t = convertToTen(N1, radix, inf);
	//找到N2中数位最大的位加1,当成二分下界
	LL low = findLargestDigit(N2);
	//上界
	LL high = max(low, t) + 1;
	//二分
	LL ans = binarySearch(N2, low, high, t);
	if(ans == -1) printf("Impossible\n");
	else printf("%lld\n", ans); 
	return 0;
}
