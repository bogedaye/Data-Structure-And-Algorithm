#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

char mp[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
					"eight", "nine"};
char str[110];//��ʼ�ַ��� 
int digit[10]; 

int main(){
	cin >> str;
	int len = strlen(str);
	int sum = 0, numlen = 0;//sumͳ������֮��, numlen
	for(int i = 0; i < len; i++){
		sum += (str[i] - '0');//�ۼ�str����λ, �õ�sum 
	} 
	if(sum == 0){//���sumΪ0 
		printf("%s", mp[0]); 
	}else{
		do{
			digit[numlen++] = sum % 10;
			sum /= 10;
		}while(sum != 0);
	}
	for(int i = numlen - 1; i >= 0; i--){
		printf("%s", mp[digit[i]]);
		if(i != 0) printf(" ");
	}
	return 0;
} 
