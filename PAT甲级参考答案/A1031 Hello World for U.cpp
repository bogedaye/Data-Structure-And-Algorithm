#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;
int main(){
	char str[90], ans[40][40];
//	cin.getline(str, N);
	cin.getline(str, 90);
	int N = strlen(str);
	int n1 = (N + 2) / 3;
	int n3 = n1; 
	int n2 = N + 2 - n1 - n3;
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			ans[i][j] = ' ';//��ʼ�� ��ans����ȫ����Ϊ�ո� 
		}
	}
	int pos = 0;//pos��0��ʼʹ��str����
	//�������¸�ֵ���n1���ַ� 
	for(int i = 1; i <= n1; i++){
		ans[i][1] = str[pos++]; 
	} 
	//�������Ҹ�ֵ�²�n2-1���ַ� 
	for(int j = 2; j <= n2; j++){
		ans[n1][j] = str[pos++];
	}	
	//�������ϸ�ֵ�ϲ�n1-1���ַ� 
	for(int k = n1-1; k >= 1; k--){
		ans[k][n2] = str[pos++]; 
	}
	//output
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			printf("%c",ans[i][j]);
		}
		printf("\n");
		
	} 
	return 0;
}
