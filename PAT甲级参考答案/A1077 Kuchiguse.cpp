#include<bits/stdc++.h>
using namespace std;

int n, minLen = 256, ans = 0;
//用字符数组做题
char s[100][260];//至多100个字符串 每个字符串至多256个字符 

int main(){
	int n;
	scanf("%d", &n);
	getchar();//接收换行符 
	for(int i = 0; i < n; i++){ 
		cin >> s[i]; 
		int len = strlen(s[i]);
		if(len < minLen) minLen = len;//取最小长度
		for(int j = 0; j < len / 2; j++){
			char temp = s[i][j];
			s[i][j] = s[i][len - 1 - j];
			s[i][len - 1 - j] = temp;
		} 
	}
	for(int i = 0; i < minLen; i++){//判断所有字符串的第i个字符是否全部相等 
		char c = s[0][i];//取第一个字符串的第i个字符
		bool same = true;
		for(int j = 1; j < n; j++){///判断其余字符串的第i个字符是否等于c 
			if(c != s[j][i]){//只要有一个不等, 就停止枚举, 说明公共前缀道词为止 
				same = false;
				break;
			}
		} 
		if(same) ans++;
		else break; 
	}
	if(ans){
		for(int i = ans - 1; i >= 0; i--){
			printf("%c", s[0][i]);
		}
	}else{
		printf("nai");
	}
	return 0;
} 
