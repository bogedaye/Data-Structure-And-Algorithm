#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std; 

int main(){
	char str1[100], str2[100];
	bool HashTable[128] = {false};//HashTable������������ַ��Ƿ����
	cin >> str1;
	cin >> str2;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; i++){
		int j;
		char c1, c2;
		for(j = 0; j < len2; j++){
			c1 = str1[i];
			c2 = str2[j];
			if(islower(c1)) c1 -= 32;
			if(islower(c2)) c2 -= 32;
			if(c1 == c2) break;//���c1�ڵڶ����ַ����г��� ������ 
		} 
		if(j == len2 && HashTable[c1] == false){//���c1�ڵڶ����ַ�����δ���� 
			printf("%c", c1);
			HashTable[c1] = true; 
		} 
	} 
	return 0;
} 
