#include<cstdio>
const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;

//upper_bound����������[L, R)�ڵ�һ������x��λ��
//ʲôʱ������[L,R]�� ʲôʱ������[L,R)�ڣ����� 
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
	scanf("%d %d", &n, &S);//Ԫ�ظ��� ��ֵS 
	sum[0]= 0; 
	for(int i = 1; i <= n; i++){
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	for(int i = 1; i <= n; i++){//ö����˵� 
		int j = upper_bound(i, n + 1, sum[i - 1] + S);//���Ҷ˵� 
		if(sum[j - 1] - sum[i - 1] == S){//���ҳɹ�(ע����j-1������j) 
			nearS = S;//��ӽ�S��ֵ����S 
			break; 
		}else if(j <= n && sum[j] - sum[i - 1] < nearS){
			//���ڴ���S�ĽⲢС��nearS
			nearS = sum[j] - sum[i - 1];//���µ�ǰnearS 
		} 
	}
	for(int i = 1; i <= n; i++){
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);
		if(sum[j - 1] - sum[i - 1] == nearS){//���ҳɹ� 
			printf("%d-%d\n", i, j - 1);//�����˵���Ҷ˵�(ע����j - 1������j) 
		}
	}
	return 0;
} 
