#include<cstdio>

int main(){
	int n, total = 0, start = 0, dest;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &dest);
		if(dest > start){
			total += (dest - start) * 6;
		}else{
			total += (start - dest) * 4;	
		}
		total += 5;
		start = dest;
	}
	printf("%d", total);
	return 0;
} 
