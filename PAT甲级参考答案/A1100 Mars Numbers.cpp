#include<cstdio> 
#include<iostream>
#include<string>
#include<map>
using namespace std; 

string geDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", 
"jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", 
"kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string numtoStr[170];//数字->火星文
map<string, int> strtoNum;//火星文->数字

//打表 
void init(){
	//以下两种情况需要特殊处理 
	//1.先考虑个位为[0,12],十位为0的数
	//2.再考虑十位为[0,12],个位为0的数 
	for(int i = 0; i < 13; i++){
		//1.先考虑个位为[0,12],十位为0的数
		numtoStr[i] = geDigit[i];
		strtoNum[geDigit[i]] = i;
		//2.再考虑十位为[0,12],个位为0的数
		numtoStr[13 * i] = tenDigit[i];
		strtoNum[tenDigit[i]] = 13 * i;
	}
	//3.接着考虑一般情况 个位和十位均不为0的数
	for(int i = 1; i < 13; i++){//十位 注意这里的i从1开始 
		for(int j = 1; j < 13; j++){//个位 注意这里的j从1开始 
			string str = tenDigit[i] + " " + geDigit[j];
			numtoStr[13 * i + j] = str;//数字->火星文
			strtoNum[str] = 13 * i + j;//火星文->数字 
		}
	}
}

int main(){
	init();//打表
	int N;
	scanf("%d%*c",&N);//%*c干嘛？？？ 
	while(N--){
		string str;
		getline(cin, str);//查询的字符串
		if(str[0] >= '0' && str[0] <= '9'){//如果是数字 字符串传换成数字 
			int num = 0;
			for(int i = 0; i < str.length(); i++){
//				num = num * 10 + str[i];
				num = num * 10 + (str[i] - '0');
			} 
			cout << numtoStr[num] << endl;//直接查表 
		}else{//如果是火星文(字符串) 
			cout << strtoNum[str] << endl;//直接查表 
		}
	} 
	return 0;
}
