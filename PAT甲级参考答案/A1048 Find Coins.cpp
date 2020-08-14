#include<cstdio>

const int maxn = 1010;
int hashTable[maxn];

int main(){
	int n, m, v1, v2, num;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		hashTable[num]++;
	}
	for(int i = 1; i <= 1000; i++){
		if(hashTable[i] && hashTable[m - i]){
			if( i == m - i && hashTable[i] <= 1){
				continue;
			} 
			printf("%d %d", i, m - i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
} 
