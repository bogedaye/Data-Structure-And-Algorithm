#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main(){
	
	char str[10010];
	cin >> str;
	int len = strlen(str);
	if(str[0] == '-') printf("-");//����Ǹ��� �������
	
	int pos = 0;//pos����ַ����е�E��λ��
	
	while(str[pos] != 'E'){
		pos++;
	}
	
	int exp = 0;
	for(int i = pos + 2; i < len; i++){
		exp = exp * 10 + (str[i] - '0');
	}
	
	//���ָ��Ϊ0 
	if(exp == 0){
		for(int i = 1; i < pos; i++){
			printf("%c", str[i]);
		}
	}
	
	//���ָ��Ϊ���� 
	if(str[pos + 1] == '-'){
		printf("0.");
		for(int i = 0; i < exp -1; i++){//���exp-1��0 
			printf("0"); 
		}
		printf("%c", str[1]);//�������С������������� 
		for(int i = 3; i < pos; i++){
			printf("%c", str[i]);
		}
	//���ָ��Ϊ���� 
	}else{
		for(int i = 1; i < pos; i++){//���С�����ƶ�֮����� 
			if(str[i] == '.') continue;
			printf("%c", str[i]);//�����ǰ��λ
			//С�������(exp + 2)λ���� 
			//��Ϊ����expλ�ð����ҳ�ʼ֮ǰ����λ 
			if(i == exp + 2 && pos - 3 > exp){
				printf(".");
			}
		} 
	}
	//���ָ��exp�Ƚϴ�, ��������0
	for(int i = 0; i < exp - (pos - 3); i++){
		printf("0");
	} 
	return 0;
} 
