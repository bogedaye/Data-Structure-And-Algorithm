#include<cstdio>
#include<string>
using namespace std;

int n;//有效位数 

string deal(string s, int& e){
	int k = 0;//s的下标 
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin());//去掉s的前导零 
	}
	if(s[0] == '.'){//若去掉前导零后是小数点 则说明s是小于1的小数 
		s.erase(s.begin());//去掉小数点 
		while(s.length() > 0 && s[0] == '0'){
			s.erase(s.begin());//去掉小数点后非零位前的所有零 
			e--;//每去掉一个零 指数e减1 
		} 
	} else{//若 
		while(k < s.length() && s[k] != '.'){
			
		} 
	}
	
}

int main(){
	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2;
	int e1 = 0, e2 = 0;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if(s3 == s4 && e1 == e2){
		cout << "YES 0." << s3 << "*10^" << e1 << endl;
	}else{
		cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
	} 
	return 0;
}
