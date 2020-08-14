#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];

//(long long)a[i]*p传给参数x 
//在[i+1,n-1]范围内查找第一个大于x的数的位置 
int binarySearch(int i,long long x){
	if(a[n-1] <= x)return n;//如果所有数都不大于x,返回n
	int leftPoint = i + 1, rightPoint = n - 1, mid;
	while(leftPoint < rightPoint){
		mid = (leftPoint + rightPoint) / 2;
		if(a[mid] <= x){
		//若a[mid]<=x 说明第一个大于x的数只能在mid后面 
		//左端点记为mid+1 
			leftPoint = mid + 1; 
		}else{
		//若a[mid]>x 说明你第一个大于x的数在mid之前(当然含mid) 
			rightPoint = mid;
		}
	}
	return leftPoint;//由于while结束时leftPoint==rightPoint 返回两者其一都可 
} 

int main(){
	scanf("%d%d",&n,&p);
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	} 
	sort(a,a + n);
	int ans = 1;
	for(int i = 0;i < n;i++){
		//在a[i+1]~a[n-1]中查找第一个超过a[i]*p的数 
		//int j = binarySearch(i,(long long)a[i]*p);//用二分查找 
		int j = upper_bound(a+i+1,a+n,(long long)a[i]*p) - a;//实际上这个函数的底层也是用的二分 
		ans = max(ans,j - i);
	}
	printf("%d\n",ans);
	return 0; 
}
