#include<cstdio>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<istream>
using namespace std;

int main(){
	char str1[10010], str2[10010];
	bool hashTable[128] = {false};
	//�����ַ�����϶����ڻ���ַ����鳤��֮ǰ ��Ҫ�ٲ�ע��д���� 
	cin.getline(str1, 10010);
	cin.getline(str2, 10010); 
	int len1 = strlen(str1);
	int len2 = strlen(str2);
//ע������ 
	//getline����string�ķ�ʽ 
//	getline(cin, str1);
//	getline(cin, str2);
	//getline����char[]�ķ�ʽ 
	for(int i = 0; i < len2; i++){
		hashTable[str2[i]] = true;
		//���������е�aeiou hashTable['a'] = false......
	}
	for(int i = 0; i < len1; i++){
		//�������Ϊʲô�ո�Ҳ�������ȥ 
		if(hashTable[str1[i]] == false){
			printf("%c", str1[i]);
		}
	}
	return 0;
}
