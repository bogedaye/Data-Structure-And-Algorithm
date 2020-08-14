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
	sprintf(str,"%d",sum);//将%d的sum转换成字符数组
	//strlen()得到数组的长度 
	int len = strlen(str);
	for(int i = 0;i<len;i++){
		printf("%c",str[i]);
//		if(((i+1)%3==0)&&(i!=(len-1))){//i=1%3==0有问题 注意啦！坑！ 
		if((i+1)%3==(len%3)&&(i!=(len-1))){
			printf(",");
		}
	} 
	return 0;
} 
