#include<cstdio>

int a[100010], hashTable[100010] = {0};

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		hashTable[a[i]]++;//����a[i]���ֵĴ�����1 
	}
	int ans = -1;
	for(int i = 0; i < n; i++){
		if(hashTable[a[i]] == 1){//���a[i]ֻ������1�� 
			ans = a[i];
			break; 
		}
	} 
	if(ans == -1) printf("None");
	else printf("%d", ans);
	return 0; 
}
