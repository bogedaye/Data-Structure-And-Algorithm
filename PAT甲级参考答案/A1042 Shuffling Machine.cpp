#include<cstdio>

const int n = 54;
int start[n+1], end[n+1], next[n+1];//next������ÿ��λ���ϵ����ڲ���֮���λ�� 
char mp[5] = {'S', 'H', 'C', 'D', 'J'};

int main(){
	int k;
	scanf("%d",&k);//the number of repeat times
	for(int i = 1; i <= n; i++){
		start[i] = i//��ʼ���Ƶı�� 
		//start[1] = 1, start[2] = 2,start[3] = 3... 
	} 
	for(int i = 1; i <= n; i++){
		scanf("%d",&next[i]);//����ÿ��λ���ϵ����ڲ������λ�� 
		//next[1] = 5, next[2] = 17, next[3] = 18, next[4] = 19... 
	} 
	for(int step = 0; step < k; step++){//ִ��k�β��� 
		for(int i = 1; i <= n; i++){
			end[next[i]] = start[i];//end[]�����������ִ�к���Ƶı��˳�� 
		//����stepΪ0ʱ end[next[1]] = start[1] = 1
		//next[1] = 5���ǰѵ�1��λ���ϵ����Ƶ���5��λ����
		//end[5] = 1  
		}
		for(int i = 1; i <= n; i++){
			start[i] = end[i];
			//��end���鸳ֵ��start�����Թ���һ��ʹ��
			//��ΪҪk�������� 
			//ִ��k�ֲ����� ����start[]�оʹ�������յ�˳�� 
		}
	} 
	for(int i = 1; i <= n; i++){
		if(i != 1)printf(" ");
		start[i]--;//��Ҫ�� 
		printf("%c%d",mp[start[i] / 13],mp[start[i] % 13]); 
		//mp[start[1]/13] = mp[]  
	} 
	return 0;
} 
