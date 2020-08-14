#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];

//(long long)a[i]*p��������x 
//��[i+1,n-1]��Χ�ڲ��ҵ�һ������x������λ�� 
int binarySearch(int i,long long x){
	if(a[n-1] <= x)return n;//�����������������x,����n
	int leftPoint = i + 1, rightPoint = n - 1, mid;
	while(leftPoint < rightPoint){
		mid = (leftPoint + rightPoint) / 2;
		if(a[mid] <= x){
		//��a[mid]<=x ˵����һ������x����ֻ����mid���� 
		//��˵��Ϊmid+1 
			leftPoint = mid + 1; 
		}else{
		//��a[mid]>x ˵�����һ������x������mid֮ǰ(��Ȼ��mid) 
			rightPoint = mid;
		}
	}
	return leftPoint;//����while����ʱleftPoint==rightPoint ����������һ���� 
} 

int main(){
	scanf("%d%d",&n,&p);
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	} 
	sort(a,a + n);
	int ans = 1;
	for(int i = 0;i < n;i++){
		//��a[i+1]~a[n-1]�в��ҵ�һ������a[i]*p���� 
		//int j = binarySearch(i,(long long)a[i]*p);//�ö��ֲ��� 
		int j = upper_bound(a+i+1,a+n,(long long)a[i]*p) - a;//ʵ������������ĵײ�Ҳ���õĶ��� 
		ans = max(ans,j - i);
	}
	printf("%d\n",ans);
	return 0; 
}
