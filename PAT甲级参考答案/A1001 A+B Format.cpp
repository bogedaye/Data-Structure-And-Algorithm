#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	int a , b , sum;
	char str[20];
	scanf("%d %d",&a,&b);
	sum = a + b;
	if(sum < 0){
		printf("-");
		sum = -sum;
	}
	sprintf(str,"%d",sum);//��%d��sumת�����ַ�����
	//strlen()�õ�����ĳ��� 
	int len = strlen(str);
	for(int i = 0;i<len;i++){
		printf("%c",str[i]);
//		if(((i+1)%3==0)&&(i!=(len-1))){//i=1%3==0������ ע�������ӣ� 
		if((i+1)%3==(len%3)&&(i!=(len-1))){
			printf(",");
		}
	} 
	return 0;
} 
