#include<cstdio>
#include<set>
using namespace std;
const int N = 51;
set<int> st[N];
//the sets are numbered from 1 to N 
void compare(int a, int b){//�Ƚϼ���a�뼯��b 
	//sameNum������¼��ͬԪ�صĸ��� distinctNum������¼��ͬԪ�صĸ��� 
	int distinctNum = st[b].size(), sameNum = 0;
	//ö�ټ���a�е�Ԫ�� �ж����Ƿ��ڼ���b�г��ֹ�
	//�������, ˵���ҵ�һ����ͬԪ�� sameNum++
	//���δ����, ˵���ҵ�һ���µĲ�ͬ��Ԫ�� distinctNum++
	//�����꼯�� ����sameNum * 100.0 / distinctNum
	//��������a
	for(set<int>::iterator it = st[a].begin();it != st[a].end(); it++){
		if(st[b].find(*it) != st[b].end())sameNum++;//��st[b]�����ҵ���Ԫ�� 
		else distinctNum++;//��st[a]�в����ҵ���Ԫ�� 
	} 
	printf("%.1f%%\n", sameNum * 100.0 / distinctNum);
}

int main(){
	int n, k, queryNumber, value, index1, index2;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			scanf("%d",&value);
			st[i].insert(value);
		}
	}
	scanf("%d",&queryNumber);//queryNumber����ѯ 
	for(int i = 0; i < queryNumber; i++){
		scanf("%d%d", &index1, &index2);//���Աȵļ��ϱ�� 
		//���ϱ�Ŷ�Ӧ����������
		compare(index1,index2);
	} 
	return 0;
} 
