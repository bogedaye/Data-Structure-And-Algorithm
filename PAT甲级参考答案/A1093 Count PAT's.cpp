#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
//数据结构:数组 
const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN];//字符串数组 
int leftNumP[MAXN] = {0};//每一位左边(含)P的个数
int rightNumT[MAXN] = {0};
int main(){
//	gets(str);//读入字符串 PAT已经取消gets的使用 提交到PAT会报compilation error 
	//改为如下的使用方法 
	cin.getline(str,MAXN); 
	int len = strlen(str);//长度
//	for(int i = 0;i < len;i++){
//		printf("%c",str[i]);
//	}
	//从左往右遍历字符串中的P 
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
	
	//法1:再用一个如上的数组rightNumT[MAXN]存放 
	//从右往左遍历字符串中的T 
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
	//在法1的基础上优化 不再用数组rightNumT[MAXN]存
	//改为用一个变量rightNumT存就好
	//因为leftNumP[MAXN]已经存好数值了 对每一个rightNumT 直接取
	//leftNumP[i]中对应的值就好了 没必要再开个rightNumT[MAXN]的数组
	//浪费空间 当然开了之后照样能AC 
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
