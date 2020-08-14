#include<cstdio>
#include<string.h>
using namespace std;

struct Node{
	char name[20];
	char password[20];
	bool ischange;
}node[1010];

//judge�ж�user��password�Ƿ���Ҫ�޸�, ����Ҫ, ���������޸Ĳ��������+1 
void judge(Node& aNode, int& cnt){//����ʹ�������� ���ԶԴ�����������޸� 
	int passwordLen = strlen(aNode.password);
	for(int i = 0; i < passwordLen; i++){
		if(aNode.password[i] == '1'){
			aNode.password[i] = '@';
			aNode.ischange = true;
			//����cnt++�Ļ� ���һ���û��������ж����ĸ��Ҫ�޸� �������ظ� 
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
	int N, cnt = 0;//ͳ����Ҫ�޸ĵ�������˻��� 
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s %s", node[i].name, node[i].password);
		node[i].ischange = false;//��ʼ�������˻������붼δ���޸� 
	}
	//��дjudge�����ж�һ���˻��������Ƿ���Ҫ�޸�
	for(int i = 0; i < N; i++){
		judge(node[i], cnt);
	}
	//�������жϺ����
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
