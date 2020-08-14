#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 1010;

struct mouse{//老鼠 
	int weight;//质量 
	int rank;//排名 
}mouse[maxn];

int main(){
	int np, ng, order;
	scanf("%d%d", &np, &ng);//总共np只老鼠 每ng只老鼠分为一组 
	for(int i = 0; i < np; i++){
		scanf("%d",&mouse[i].weight);
	}
	queue<int> q;//定义一个队列
	for(int i = 0; i < np; i++){
		scanf("%d", &order);//题目给出的顺序号
		q.push(order);//按顺序把老鼠们的标号入队 
	} 
	int temp = np, group;//temp为当前轮的比赛总老鼠数, group为组数
	while(q.size() != 1){
		//计算group, 即当前轮分为几组进行比赛
		if(temp % ng == 0) group = temp / ng;
		else group = temp / ng + 1;
		//枚举每一组, 选出该组质量最大的老鼠的编号
		for(int i = 0; i < group; i++){
			int k = q.front();//k存放质量最大的老鼠编号 
			for(int j = 0; j < ng; j++){
				//在最后一组老鼠数不足ng时起作用 退出循环
				if(i * ng + j >= temp)break;
				int front = q.front();
				if(mouse[front].weight > mouse[k].weight){
					k = front;//找出质量最大的老鼠 
				} 
				mouse[front].rank = group + 1;//该轮老鼠为group + 1
				q.pop();//出队这只老鼠 
			} 
			q.push(k);//把胜利的老鼠晋级 
		} 
		temp = group;//group只老鼠晋级 因为下轮晋级的总老鼠数为group 
	} 
	mouse[q.front()].rank = 1;//当队列只剩下一只老鼠时 令其排名为1
	//输出所有老鼠的信息
	for(int i = 0; i < np; i++){
		printf("%d",mouse[i].rank);
		if(i < np - 1)printf(" ");
	} 
	return 0;
}
