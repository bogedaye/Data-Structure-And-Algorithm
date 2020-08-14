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
			ans[i][j] = ' ';//初始化 将ans数组全部赋为空格 
		}
	}
	int pos = 0;//pos从0开始使用str数组
	//从上往下赋值左侧n1个字符 
	for(int i = 1; i <= n1; i++){
		ans[i][1] = str[pos++]; 
	} 
	//从左往右赋值下侧n2-1个字符 
	for(int j = 2; j <= n2; j++){
		ans[n1][j] = str[pos++];
	}	
	//从下往上赋值上侧n1-1个字符 
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
