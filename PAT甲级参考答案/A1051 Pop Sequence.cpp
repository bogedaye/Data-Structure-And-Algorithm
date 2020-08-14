#include<cstdio>
#include<stack>
using namespace std;

const int maxn = 1010;
int arr[maxn];//������Ŀ�����ĳ�ջ����
stack<int> st;//����ջst

int main(){
	int m, n, T;//ջ������ ���еĳ��� Ҫ���ĵ������е����� 
	scanf("%d%d%d", &m, &n, &T);
	while(T--){//ѭ��ִ��T��
		//��ÿ����ջ��������ǰһ��Ҫ���ջ, ����, ���
		//�ϸ���ջ���еĽ��û�б���� ��ô��Ӱ���¸���ջ
		//���еĹ��� 
		while(!st.empty()){//���ջ 
			st.pop();
		} 
		
		for(int i = 1; i <= n; i++){//�������� 
			scanf("%d",&arr[i]);
		}
		
		int current = 1;//ָ���ջ�����еĴ���ջԪ��
		bool flag = true;
		
		for(int i = 1; i <= n; i++){
			st.push(i);//��iѹ��ջ
			if(st.size() > m){//�����ʱջ��Ԫ�ظ�����������m,�����зǷ� 
				flag = false;
				break;
			} 
			//ջ��Ԫ�����ջ���е�ǰλ�õ�Ԫ����ͬʱ
			//�����㷨
			//����ջ�Ĺ����� �����ջ��Ԫ��ǡ�õ��ڳ�ջ���е�ǰ�ȴ���ջ��
			//Ԫ�أ���ô����ջ��Ԫ�س�ջ ͬʱ�ѳ�ջ���е�ǰ�ȴ���ջ��
			//Ԫ��λ�ú���1λ 
			while(!st.empty() && st.top() == arr[current]){
				st.pop();//������ջ����current++;
				current++;
			} 
		}  
		if(st.empty() == true && flag == true){
			printf("YES\n");//ջ����flag==trueʱ�����Ϸ� 
		}else{
			printf("NO\n");
		} 
	}
	return 0;
} 
