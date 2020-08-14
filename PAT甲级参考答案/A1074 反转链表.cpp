//此题还未理解 
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Node{//步骤1 定义静态链表 
	int address, data, next;
	int order;//结点在链表上的序号 无效点记为maxn
}node[maxn];

bool cmp(Node a, Node b){
	return a.order < b.order;
}

int main(){
	for(int i = 0; i < maxn; i++){//步骤2 初始化 
		node[i].order = maxn;//初始化全部为无效结点 
	}
	int begin, n, k, address;
	scanf("%d%d%d",&begin,&n,&k);//起点地址 结点个数 要求反转的子链结点的个数
	for(int i = 0; i < n; i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address = address;
	}
	int p = begin, count = 0;//count计数有效结点的数目 
	while(p != -1){//步骤3 遍历找出单链表所有有效结点 
		node[p].order = count++;//结点在单链表中的序号
		p = node[p].next;//下一个结点 
	} 
	sort(node, node + maxn, cmp);//步骤4 按单链表从头到尾排序
	//有效结点为前count个结点 为了下面书写方便 因此把count赋给n
	n = count;
	//单链表已经形成 步骤5 下面按题目的要求输出
	for(int i = 0; i < n / k; i++){//枚举完整的 n / k块
		for(int j = (i + 1) * k - 1; j > i * k; j--){//第j块倒着输出 
			printf("%05d %d %05d\n",node[j].address, node[j].data, node[j-1].address); 
		}
		//下面是每一块的最后一个结点的next地址的处理
		printf("%05d %d ",node[i * k].address, node[i * k].data);
		if(i < n / k - 1){
			printf("%05d\n", node[(i + 2) * k - 1].address);
		} else{//是最后一块时 
			if(n % k == 0){//恰好是最后一个结点 输出-1 
				printf("-1\n"); 
			}else{//剩下不完整的块按原先的顺序输出 
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
