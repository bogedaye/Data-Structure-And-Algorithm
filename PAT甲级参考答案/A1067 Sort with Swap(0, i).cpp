#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int pos[maxn];//��Ÿ����ֵ�ǰ������λ�õı�� 

int main(){
	int n, ans = 0;//ans��ʾ�ܽ������� 
	scanf("%d", &n);
	int left = n - 1, num;//left��ų�0���ⲻ�ڱ�λ�ϵ����ĸ��� 
	
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		pos[num] = i;//num����λ��Ϊi
		if(num == i && num != 0){//�����0�����б�λ�ϵ��� 
			left--; 
		}
	} 
	
	int k = 1;//k��ų�0���⵱ǰ���ڱ�λ�ϵ���С����
	while(left > 0){//ֻҪ���������ڱ�λ�� 
		//���0�ڱ�λ�� ��Ѱ��һ����ǰ���ڱ�λ�ϵ�����0����
		if(pos[0] = 0){
			while(k < n){
				if(pos[k] != k){//�ҵ�һ����ǰ���ڱ�λ�ϵ���k 
					swap(pos[0], pos[k]);//��k��0����λ�� 
					ans++;//����������1 
					break;
				}
				k++;//�ж�k+1�Ƿ��ڱ�λ
			}
		} 
		//ֻҪ0���ڱ�λ �ͽ�0����λ�õ����ĵ�ǰλ����0��λ�ý���
		while(pos[0] != 0){
			swap(pos[0], pos[pos[0]]);//0��pos[0]����
			ans++;
			left--; 
		} 
	} 
	printf("%d", ans); 
	return 0;
} 
