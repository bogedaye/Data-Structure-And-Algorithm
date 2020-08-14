#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100010;
const int INF = 0x3fffffff;
//aΪ����,leftMax��rightMin�ֱ�Ϊÿһλ������������ұ���С����
int a[MAXN], leftMax[MAXN], rightMin[MAXN];
//ans��¼������Ԫ numΪ��Ԫ����
int ans[MAXN], num = 0;
int main(){
	int n;
	scanf("%d",&n);//����Ԫ�ظ���
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);//��������Ԫ�� 
	} 
	//Ϊʲô��������leftMax[0] = 0��?���Ը�ֵ����ֵ��? 
	leftMax[0] = 0;//A[0]���û�б��������
	for(int i = 1;i < n;i++){
		leftMax[i] = max(leftMax[i-1],a[i-1]);//��i-1�Ƶ�i 
	} 
	//Ϊʲô������rightMin[n-1] = INF��?���Ը�ֵ����ֵ��? 
	rightMin[n-1] = INF;//A[n-1]�ұ�û�б���С����
	for(int i = n - 2;i >= 0;i--){
		rightMin[i] = min(rightMin[i+1],a[i+1]);
	}
	for(int i = 0;i < n;i++){
		//���������������С���ұ���������������
		if(leftMax[i] < a[i] && rightMin[i] > a[i]){
			ans[num++] = a[i];//��¼��Ԫ 
		} 
	}
	printf("%d\n",num);//�����Ԫ����
	for(int i = 0;i < num;i++){
		printf("%d",ans[i]);//�������������Ԫ
		if(i < num - 1)printf(" "); 
	} 
	printf("\n");
	return 0;
} 
