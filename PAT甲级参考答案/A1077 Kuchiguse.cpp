#include<bits/stdc++.h>
using namespace std;

int n, minLen = 256, ans = 0;
//���ַ���������
char s[100][260];//����100���ַ��� ÿ���ַ�������256���ַ� 

int main(){
	int n;
	scanf("%d", &n);
	getchar();//���ջ��з� 
	for(int i = 0; i < n; i++){ 
		cin >> s[i]; 
		int len = strlen(s[i]);
		if(len < minLen) minLen = len;//ȡ��С����
		for(int j = 0; j < len / 2; j++){
			char temp = s[i][j];
			s[i][j] = s[i][len - 1 - j];
			s[i][len - 1 - j] = temp;
		} 
	}
	for(int i = 0; i < minLen; i++){//�ж������ַ����ĵ�i���ַ��Ƿ�ȫ����� 
		char c = s[0][i];//ȡ��һ���ַ����ĵ�i���ַ�
		bool same = true;
		for(int j = 1; j < n; j++){///�ж������ַ����ĵ�i���ַ��Ƿ����c 
			if(c != s[j][i]){//ֻҪ��һ������, ��ֹͣö��, ˵������ǰ׺����Ϊֹ 
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
