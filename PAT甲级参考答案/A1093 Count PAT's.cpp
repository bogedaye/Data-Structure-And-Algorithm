#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
//���ݽṹ:���� 
const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN];//�ַ������� 
int leftNumP[MAXN] = {0};//ÿһλ���(��)P�ĸ���
int rightNumT[MAXN] = {0};
int main(){
//	gets(str);//�����ַ��� PAT�Ѿ�ȡ��gets��ʹ�� �ύ��PAT�ᱨcompilation error 
	//��Ϊ���µ�ʹ�÷��� 
	cin.getline(str,MAXN); 
	int len = strlen(str);//����
//	for(int i = 0;i < len;i++){
//		printf("%c",str[i]);
//	}
	//�������ұ����ַ����е�P 
	for(int i = 0;i < len;i++){
		if(i > 0){
			leftNumP[i] = leftNumP[i-1]; 	
		}
		if(str[i] == 'P'){
			leftNumP[i]++;
		}
//		printf("%d",leftNumP[i]);
	} 
//	printf("\n");
	
	//��1:����һ�����ϵ�����rightNumT[MAXN]��� 
	//������������ַ����е�T 
//	for(int i = len - 1;i >= 0;i--){
//		if(i < len - 1){
//			rightNumT[i] = rightNumT[i+1];
//		}
//		if(str[i] == 'T'){
//			rightNumT[i]++;
//		}
////		printf("%d",rightNumT[i]);
//	} 
//	int ans = 0;
//	for(int i = 0;i < len;i++){
//		if(str[i] == 'A'){
//			ans = (ans + leftNumP[i]*rightNumT[i]) % MOD;
//		}
//	} 
	//�ڷ�1�Ļ������Ż� ����������rightNumT[MAXN]��
	//��Ϊ��һ������rightNumT��ͺ�
	//��ΪleftNumP[MAXN]�Ѿ������ֵ�� ��ÿһ��rightNumT ֱ��ȡ
	//leftNumP[i]�ж�Ӧ��ֵ�ͺ��� û��Ҫ�ٿ���rightNumT[MAXN]������
	//�˷ѿռ� ��Ȼ����֮��������AC 
	int ans = 0 , rightNumT = 0;
	for(int i = len - 1;i >= 0;i--){
		if(str[i] == 'T'){
			rightNumT++; 
		}
		else if(str[i] == 'A'){
			ans = (ans + rightNumT*leftNumP[i]) % MOD; 
		} 
	} 
	printf("%d\n",ans);
	return 0;
} 
