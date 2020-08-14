#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;

char day[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(){
	char str1[70], str2[70], str3[70], str4[70];
	cin >> str1 >> str2 >> str3 >> str4;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	int i;
	//寻找str1和str2中第一对相同位置对应的 
	for(i = 0; i < len1 && i < len2; i++){
		if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G'){
			printf("%s ", day[str1[i] - 'A']);
			break;
		}
	}
	//往后寻找str1和str2中第二对相同位置对应的 A-N 
	for(i++; i< len1 && i < len2; i++){
//		printf("%d\n",i);
		if(str1[i] == str2[i]){
			if(str1[i] >= '0' && str1[i] <= '9'){
				printf("%02d:", str1[i] - '0');
				break;
			}else if(str1[i] >= 'A' && str1[i] <= 'N'){
				printf("%02d:", str1[i] - 'A' + 10);
				break;
			}
		}
	}
	//寻找str3和str4中第一对相同的位置
	for(int i = 0; i < len3 && i < len4; i++){
		if(str3[i] == str4[i]){
			if((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z')){
				printf("%02d",i);
				break;
			} 
		}
	} 
	return 0;
}
