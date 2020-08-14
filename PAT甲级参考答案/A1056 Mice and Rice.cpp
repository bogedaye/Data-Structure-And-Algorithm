#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 1010;

struct mouse{//���� 
	int weight;//���� 
	int rank;//���� 
}mouse[maxn];

int main(){
	int np, ng, order;
	scanf("%d%d", &np, &ng);//�ܹ�npֻ���� ÿngֻ�����Ϊһ�� 
	for(int i = 0; i < np; i++){
		scanf("%d",&mouse[i].weight);
	}
	queue<int> q;//����һ������
	for(int i = 0; i < np; i++){
		scanf("%d", &order);//��Ŀ������˳���
		q.push(order);//��˳��������ǵı����� 
	} 
	int temp = np, group;//tempΪ��ǰ�ֵı�����������, groupΪ����
	while(q.size() != 1){
		//����group, ����ǰ�ַ�Ϊ������б���
		if(temp % ng == 0) group = temp / ng;
		else group = temp / ng + 1;
		//ö��ÿһ��, ѡ������������������ı��
		for(int i = 0; i < group; i++){
			int k = q.front();//k����������������� 
			for(int j = 0; j < ng; j++){
				//�����һ������������ngʱ������ �˳�ѭ��
				if(i * ng + j >= temp)break;
				int front = q.front();
				if(mouse[front].weight > mouse[k].weight){
					k = front;//�ҳ������������� 
				} 
				mouse[front].rank = group + 1;//��������Ϊgroup + 1
				q.pop();//������ֻ���� 
			} 
			q.push(k);//��ʤ����������� 
		} 
		temp = group;//groupֻ������� ��Ϊ���ֽ�������������Ϊgroup 
	} 
	mouse[q.front()].rank = 1;//������ֻʣ��һֻ����ʱ ��������Ϊ1
	//��������������Ϣ
	for(int i = 0; i < np; i++){
		printf("%d",mouse[i].rank);
		if(i < np - 1)printf(" ");
	} 
	return 0;
}
