//���⻹δ��� 
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Node{//����1 ���徲̬���� 
	int address, data, next;
	int order;//����������ϵ���� ��Ч���Ϊmaxn
}node[maxn];

bool cmp(Node a, Node b){
	return a.order < b.order;
}

int main(){
	for(int i = 0; i < maxn; i++){//����2 ��ʼ�� 
		node[i].order = maxn;//��ʼ��ȫ��Ϊ��Ч��� 
	}
	int begin, n, k, address;
	scanf("%d%d%d",&begin,&n,&k);//����ַ ������ Ҫ��ת���������ĸ���
	for(int i = 0; i < n; i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address = address;
	}
	int p = begin, count = 0;//count������Ч������Ŀ 
	while(p != -1){//����3 �����ҳ�������������Ч��� 
		node[p].order = count++;//����ڵ������е����
		p = node[p].next;//��һ����� 
	} 
	sort(node, node + maxn, cmp);//����4 ���������ͷ��β����
	//��Ч���Ϊǰcount����� Ϊ��������д���� ��˰�count����n
	n = count;
	//�������Ѿ��γ� ����5 ���水��Ŀ��Ҫ�����
	for(int i = 0; i < n / k; i++){//ö�������� n / k��
		for(int j = (i + 1) * k - 1; j > i * k; j--){//��j�鵹����� 
			printf("%05d %d %05d\n",node[j].address, node[j].data, node[j-1].address); 
		}
		//������ÿһ������һ������next��ַ�Ĵ���
		printf("%05d %d ",node[i * k].address, node[i * k].data);
		if(i < n / k - 1){
			printf("%05d\n", node[(i + 2) * k - 1].address);
		} else{//�����һ��ʱ 
			if(n % k == 0){//ǡ�������һ����� ���-1 
				printf("-1\n"); 
			}else{//ʣ�²������Ŀ鰴ԭ�ȵ�˳����� 
				printf("%05d\n",node[(i + 1) * k].address);
				for(int i = n / k * k; i < n; i++){
					printf("%05d %d ",node[i].address, node[i].data);
					if(i < n - 1){
						printf("%05d\n", node[i+1].address);
					}else{
						printf("-1\n");
					}
				}	
			}
		}
	}
	return 0;	
}
