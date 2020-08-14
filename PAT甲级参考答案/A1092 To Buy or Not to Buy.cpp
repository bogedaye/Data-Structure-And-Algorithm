#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

const int maxn = 1010;
//HashTable记录第一串中每个颜色珠子的个数 miss记录缺少的珠子的个数 
int HashTable[80] = {0}, miss = 0; 

//将数字和字母转换成HashTable的下标
int change(char c){
	if(c >= '0' && c <= '9') return c - '0';//数字 
	else if(c >= 'a' && c <= 'z') return c - 'a' + 10;//小写字母 
	else if(c >= 'A' && c <= 'Z') return c - 'A' + 36;//大写字母 
} 

int main(){
	char str1[maxn], str2[maxn];
	cin >> str1;//第一串 
	cin >> str2;//第二串 
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; i++){//遍历第一串 
		int index = change(str1[i]);//字符->HashTable下标
		HashTable[index]++;//该颜色个数加1 
	} 
	for(int j = 0; j < len2; j++){//遍历第二串 
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
