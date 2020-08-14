#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 10010;
string str[maxn];

bool cmp(string a, string b){
	return a + b < b + a;//如果a + b < b + a, 就把a排在前面 
} 

int main(){
	int n;
	string ans;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		cin >> str[i];
	}
	sort(str, str + n, cmp);//排序 
	for(int i = 0; i < n; i++){
		ans += str[i];
	} 
	while(ans.size() != 0 && ans[0] == '0'){
		ans.erase(ans.begin());
	}
	if(ans.size() == 0) cout << 0;//去除前导零为空 则输出0
	else cout << ans; 
	return 0;
} 
