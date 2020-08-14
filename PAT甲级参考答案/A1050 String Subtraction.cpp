#include<cstdio>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<istream>
using namespace std;

int main(){
	char str1[10010], str2[10010];
	bool hashTable[128] = {false};
	//读入字符数组肯定是在获得字符数组长度之前 不要再不注意写错了 
	cin.getline(str1, 10010);
	cin.getline(str2, 10010); 
	int len1 = strlen(str1);
	int len2 = strlen(str2);
//注意区分 
	//getline读入string的方式 
//	getline(cin, str1);
//	getline(cin, str2);
	//getline读入char[]的方式 
	for(int i = 0; i < len2; i++){
		hashTable[str2[i]] = true;
		//比如样例中的aeiou hashTable['a'] = false......
	}
	for(int i = 0; i < len1; i++){
		//奇怪这里为什么空格也能输出出去 
		if(hashTable[str1[i]] == false){
			printf("%c", str1[i]);
		}
	}
	return 0;
}
