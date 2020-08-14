#include<cstdio> 
#include<iostream>
#include<string>
#include<map>
using namespace std; 

string geDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", 
"jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", 
"kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string numtoStr[170];//����->������
map<string, int> strtoNum;//������->����

//��� 
void init(){
	//�������������Ҫ���⴦�� 
	//1.�ȿ��Ǹ�λΪ[0,12],ʮλΪ0����
	//2.�ٿ���ʮλΪ[0,12],��λΪ0���� 
	for(int i = 0; i < 13; i++){
		//1.�ȿ��Ǹ�λΪ[0,12],ʮλΪ0����
		numtoStr[i] = geDigit[i];
		strtoNum[geDigit[i]] = i;
		//2.�ٿ���ʮλΪ[0,12],��λΪ0����
		numtoStr[13 * i] = tenDigit[i];
		strtoNum[tenDigit[i]] = 13 * i;
	}
	//3.���ſ���һ����� ��λ��ʮλ����Ϊ0����
	for(int i = 1; i < 13; i++){//ʮλ ע�������i��1��ʼ 
		for(int j = 1; j < 13; j++){//��λ ע�������j��1��ʼ 
			string str = tenDigit[i] + " " + geDigit[j];
			numtoStr[13 * i + j] = str;//����->������
			strtoNum[str] = 13 * i + j;//������->���� 
		}
	}
}

int main(){
	init();//���
	int N;
	scanf("%d%*c",&N);//%*c������� 
	while(N--){
		string str;
		getline(cin, str);//��ѯ���ַ���
		if(str[0] >= '0' && str[0] <= '9'){//��������� �ַ������������� 
			int num = 0;
			for(int i = 0; i < str.length(); i++){
//				num = num * 10 + str[i];
				num = num * 10 + (str[i] - '0');
			} 
			cout << numtoStr[num] << endl;//ֱ�Ӳ�� 
		}else{//����ǻ�����(�ַ���) 
			cout << strtoNum[str] << endl;//ֱ�Ӳ�� 
		}
	} 
	return 0;
}
