#include<map>
#include<cstdio>
#include<iostream>
using namespace std;

bool check(char c){//����ַ�c�Ƿ���[0,9]��[A,Z]��[a,z] 
	if(c >= '0' && c <= '9') return true;
	if(c >= 'A' && c <= 'Z') return true;
	if(c >= 'a' && c <= 'z') return true;
	return false;
} 

int main(){
	map<string, int> count;//count�����ַ������ֵĴ���
	string str;
	getline(cin, str);//���������ַ���
	int i = 0;//�±� 
	while(i < str.length()){//���ַ�����Χ��
		string word;//����
		
		while(i < str.length() && check(str[i])){//����ǵ��ʵ��ַ� 
			if(str[i] >= 'A' && str[i] <= 'Z'){
				str[i] += 32;//����д��ĸת��ΪСд��ĸ
			}
			word += str[i];
			i++; 
		}
		
		if(word != ""){
			if(count.find(word) == count.end())count = 1;
			else count++;
		}

		while(i < str.length() && check(str[i]) == false){
			i++;//�����ǵ����ַ� 
		} 
		
	} 
	string ans;//��ų��ִ������ĵ��� 
	int MAX = 0;//�������ĵ��ʵĴ��� 
	for(map<string, int>::iterator it = count.begin(); it != count.end(); it++){
		if(it -> second > MAX){
			MAX = it -> second;
			ans = it -> first;
		}
	} 
	cout << ans << " " << MAX << endl;//������ 
	return 0;
}
