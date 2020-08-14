#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

const int maxn = 1010;
//HashTable��¼��һ����ÿ����ɫ���ӵĸ��� miss��¼ȱ�ٵ����ӵĸ��� 
int HashTable[80] = {0}, miss = 0; 

//�����ֺ���ĸת����HashTable���±�
int change(char c){
	if(c >= '0' && c <= '9') return c - '0';//���� 
	else if(c >= 'a' && c <= 'z') return c - 'a' + 10;//Сд��ĸ 
	else if(c >= 'A' && c <= 'Z') return c - 'A' + 36;//��д��ĸ 
} 

int main(){
	char str1[maxn], str2[maxn];
	cin >> str1;//��һ�� 
	cin >> str2;//�ڶ��� 
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; i++){//������һ�� 
		int index = change(str1[i]);//�ַ�->HashTable�±�
		HashTable[index]++;//����ɫ������1 
	} 
	for(int j = 0; j < len2; j++){//�����ڶ��� 
		int index = change(str2[j]);
		HashTable[index]--;
		if(HashTable[index] < 0){
			miss++;
		} 
	} 
	if(miss > 0) printf("No %d", miss);
	else printf("Yes %d", len1 - len2);
	return 0;
}
