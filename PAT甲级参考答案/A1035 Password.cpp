#include<cstdio>
#include<string.h>
using namespace std;

struct Node{
	char name[20];
	char password[20];
	bool ischange;
}node[1010];

//judge判断user的password是否需要修改, 若需要, 则对其进行修改并令计数器+1 
void judge(Node& aNode, int& cnt){//参数使用了引用 可以对传入参数进行修改 
	int passwordLen = strlen(aNode.password);
	for(int i = 0; i < passwordLen; i++){
		if(aNode.password[i] == '1'){
			aNode.password[i] = '@';
			aNode.ischange = true;
			//这里cnt++的话 如果一个用户的密码有多个字母需要修改 则会产生重复 
//			cnt++; 
		}else if(aNode.password[i] == '0'){
			aNode.password[i] = '%';
			aNode.ischange = true;
//			cnt++;
		}else if(aNode.password[i] == 'l'){
			aNode.password[i] = 'L';
			aNode.ischange = true;
//			cnt++;
		}else if(aNode.password[i] == 'O'){
			aNode.password[i] = 'o';
			aNode.ischange = true;
//			cnt++;	
		}
	} 
	if(aNode.ischange == true){
		cnt++;
	} 
} 

int main(){
	int N, cnt = 0;//统计需要修改的密码的账户数 
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s %s", node[i].name, node[i].password);
		node[i].ischange = false;//初始化所有账户的密码都未被修改 
	}
	//编写judge函数判断一个账户的密码是否需要修改
	for(int i = 0; i < N; i++){
		judge(node[i], cnt);
	}
	//按题意判断后输出
	if(cnt == 0){
		if(N != 1){
			printf("There are %d accounts and no account is modified", N);
		}else if(N == 1){
			printf("There is 1 account and no account is modified");
		}
	}else{
		printf("%d\n", cnt);
		for(int i = 0; i < N; i++){
			if(node[i].ischange == true){
				printf("%s %s\n", node[i].name, node[i].password);
			}
		}
	}
	return 0;
}
