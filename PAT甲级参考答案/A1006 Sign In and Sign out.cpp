#include<cstdio>
#include<iostream>
using namespace std;

struct Node{
	char id[20];
	int hh, mm, ss;
}temp, ans1, ans2;

bool cmp(Node a, Node b){
	if(a.hh != b.hh) return a.hh > b.hh;
	if(a.mm != b.mm) return a.mm > b.mm;
	return a.ss > b.ss;
} 

int main(){
	int m;
	scanf("%d", &m);
	ans1.hh = 24, ans1.mm = 60, ans1.ss = 60;//�ѳ�ʼǩ��ʱ�������� 
	ans2.hh = 0, ans2.mm = 0, ans2.ss = 0;//�ѳ�ʼǩ��ʱ�������С 
	for(int i = 0; i < m; i++){
		//�ȶ���ǩ��ʱ�� 
		scanf("%s %d:%d:%d", temp.id, &temp.hh, &temp.mm, &temp.ss);
		if(cmp(temp, ans1) == false) ans1 = temp;
		//�ٶ���ǩ��ʱ�� 
		scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
		if(cmp(temp, ans2) == true) ans2 = temp;
	}
	printf("%s %s", ans1.id, ans2.id);
	return 0; 
}
