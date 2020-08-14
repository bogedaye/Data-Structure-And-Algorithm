#include<cstdio>
#include<algorithm>
using namespace std; 

bool cmp(int a, int b){
	return a > b;
}

void toArray(int n, int num[]){
	for(int i = 0; i < 4; i++){
		num[i] = n % 10;
		n /= 10;
	}
}

int toNumber(int num[]){
	int ans = 0;
	for(int i = 0; i < 4; i++){
		ans = ans * 10 + num[i];
	} 
	return ans;
}

int main(){
	int n, max, min;
	scanf("%d", &n);
	int num[5];
	while(1){
		toArray(n, num);
		sort(num, num + 4);
		min = toNumber(num);
		sort(num, num + 4, cmp);
		max = toNumber(num);
		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);
		if(n == 6174 || n == 0) break;
	}
	return 0;
}
