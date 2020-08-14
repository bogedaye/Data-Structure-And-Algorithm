#include<cstdio>
#include<stack>
using namespace std;

const int maxn = 1010;
int arr[maxn];//保存题目给出的出栈序列
stack<int> st;//定义栈st

int main(){
	int m, n, T;//栈的容量 序列的长度 要检查的弹出序列的数量 
	scanf("%d%d%d", &m, &n, &T);
	while(T--){//循环执行T次
		//在每个出栈序列输入前一定要清空栈, 否则, 如果
		//上个出栈序列的结果没有被清空 那么会影响下个出栈
		//序列的过程 
		while(!st.empty()){//清空栈 
			st.pop();
		} 
		
		for(int i = 1; i <= n; i++){//读入数据 
			scanf("%d",&arr[i]);
		}
		
		int current = 1;//指向出栈序列中的待出栈元素
		bool flag = true;
		
		for(int i = 1; i <= n; i++){
			st.push(i);//把i压入栈
			if(st.size() > m){//如果此时栈中元素个数大于容量m,则序列非法 
				flag = false;
				break;
			} 
			//栈顶元素与出栈序列当前位置的元素相同时
			//核心算法
			//在入栈的过程中 如果入栈的元素恰好等于出栈序列当前等待出栈的
			//元素，那么就让栈顶元素出栈 同时把出栈序列当前等待出栈的
			//元素位置后移1位 
			while(!st.empty() && st.top() == arr[current]){
				st.pop();//反复弹栈并令current++;
				current++;
			} 
		}  
		if(st.empty() == true && flag == true){
			printf("YES\n");//栈空且flag==true时表明合法 
		}else{
			printf("NO\n");
		} 
	}
	return 0;
} 
