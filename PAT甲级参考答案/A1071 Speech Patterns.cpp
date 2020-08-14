#include<map>
#include<cstdio>
#include<iostream>
using namespace std;

bool check(char c){//检查字符c是否是[0,9]、[A,Z]、[a,z] 
	if(c >= '0' && c <= '9') return true;
	if(c >= 'A' && c <= 'Z') return true;
	if(c >= 'a' && c <= 'z') return true;
	return false;
} 

int main(){
	map<string, int> count;//count计数字符串出现的次数
	string str;
	getline(cin, str);//读入整行字符串
	int i = 0;//下标 
	while(i < str.length()){//在字符串范围内
		string word;//单词
		
		while(i < str.length() && check(str[i])){//如果是单词的字符 
			if(str[i] >= 'A' && str[i] <= 'Z'){
				str[i] += 32;//将大写字母转换为小写字母
			}
			word += str[i];
			i++; 
		}
		
		if(word != ""){
			if(count.find(word) == count.end())count = 1;
			else count++;
		}

		while(i < str.length() && check(str[i]) == false){
			i++;//跳过非单词字符 
		} 
		
	} 
	string ans;//存放出现次数最多的单词 
	int MAX = 0;//出现最多的单词的次数 
	for(map<string, int>::iterator it = count.begin(); it != count.end(); it++){
		if(it -> second > MAX){
			MAX = it -> second;
			ans = it -> first;
		}
	} 
	cout << ans << " " << MAX << endl;//输出结果 
	return 0;
}
