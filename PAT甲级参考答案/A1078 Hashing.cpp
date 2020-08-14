#include<cstdio>
#include<cmath>

const int N  = 11111;

bool hashTable[N] = {0};

bool isPrime(int n){
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){
	int n, TSize, a;
	scanf("%d %d", &TSize, &n);
	while(isPrime(TSize) == false){
		TSize++;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		int M = a % TSize;
		if(hashTable[M] == false){
			hashTable[M] = true;
			if(i == 0) printf("%d", M);
			else printf(" %d", M);
		} else{
			int step;
			for(step = 1; step < TSize; step++){
				M = (a + step * step) % TSize;
				if(hashTable[M] == false){
					hashTable[M] == true;
					if(i == 0) printf("%d", M);
					else printf(" %d", M); 
					break;//???为啥要break这里 
				}
			}	
			if(step >= TSize){
				if(i > 0) printf(" ");
				printf("-");
			}
		}
	}
	return 0;
} 
