#include<cstdio>
#include<cmath>

const int maxn = 110;
int d[maxn];

bool isPrime(int n){
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++){
		if(n % i == 0) return false;
	}
	return true;
} 

int main(){
	int n, radix;
//	int ans = 0;
	while(scanf("%d", &n) != EOF){
		if(n < 0) break;
		int ans = 0; 
		scanf("%d", &radix);
		if(isPrime(n) == false){
			printf("No\n");
		}else{
			int len = 0;
			do{
				d[len++] = n % radix;
				n /= radix; 
			}while(n != 0);
			for(int i = 0; i < len; i++){
				//Ϊʲô�Ҷ���ans = 0 �ύ��pat�ϻᲿ�ִ��� ʲô�� 
				//ans��λ�� �ֲ�������λ��һ��Ҫע�� ������ 
				ans = ans * radix + d[i]; 
//				n = n * radix + d[i];
			}
			if(isPrime(ans) == true) printf("Yes\n");
			
//			if(isPrime(n) == true) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
} 
