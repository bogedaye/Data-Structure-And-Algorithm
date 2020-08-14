#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main(){
	
	char str[10010];
	cin >> str;
	int len = strlen(str);
	if(str[0] == '-') printf("-");//如果是负数 输出负号
	
	int pos = 0;//pos存放字符串中的E的位置
	
	while(str[pos] != 'E'){
		pos++;
	}
	
	int exp = 0;
	for(int i = pos + 2; i < len; i++){
		exp = exp * 10 + (str[i] - '0');
	}
	
	//如果指数为0 
	if(exp == 0){
		for(int i = 1; i < pos; i++){
			printf("%c", str[i]);
		}
	}
	
	//如果指数为负数 
	if(str[pos + 1] == '-'){
		printf("0.");
		for(int i = 0; i < exp -1; i++){//输出exp-1个0 
			printf("0"); 
		}
		printf("%c", str[1]);//输出除了小数点以外的数字 
		for(int i = 3; i < pos; i++){
			printf("%c", str[i]);
		}
	//如果指数为正数 
	}else{
		for(int i = 1; i < pos; i++){//输出小数点移动之后的数 
			if(str[i] == '.') continue;
			printf("%c", str[i]);//输出当前数位
			//小数点加在(exp + 2)位置上 
			//因为右移exp位置啊并且初始之前有两位 
			if(i == exp + 2 && pos - 3 > exp){
				printf(".");
			}
		} 
	}
	//如果指数exp比较大, 输出多余的0
	for(int i = 0; i < exp - (pos - 3); i++){
		printf("0");
	} 
	return 0;
} 
