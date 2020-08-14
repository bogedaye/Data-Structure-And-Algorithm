#include<cstdio>

bool judge(int z[], int num){
	for(int i = 0; i < num / 2; i++){
		if(z[i] != z[num - 1 - i]) return false;
	}
	return true;
}

int main(){
	int N, b, Q;
	scanf("%d %d", &N, &b);
	int z[40], num = 0;
	do{
		z[num++] = N % b;
		N /= b; 
	}while(N != 0);
	bool flag = judge(z, num);
	if(flag == true){
		printf("Yes\n");
		for(int i = num - 1; i > 0; i--){
			printf("%d ", z[i]);
		}
		printf("%d", z[0]);
	} else{
		printf("No\n");
		for(int i = num - 1; i > 0; i--){
			printf("%d ", z[i]);
		} 
		printf("%d", z[0]);
	}
	return 0;
}
