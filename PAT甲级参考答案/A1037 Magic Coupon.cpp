#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int coupon[maxn], product[maxn];
int main(){
	int nc, np;
	scanf("%d", &nc);
	for(int i = 0; i < nc; i++){
		scanf("%d",&coupon[i]);
	}
	scanf("%d",&np);
	for(int j = 0; j < np; j++){
		scanf("%d",&product[j]);
	}
	sort(coupon, coupon + nc);
	sort(product, product + np);
	int i = 0, j = 0, ans = 0;
	while(i < nc && j < np && coupon[i] < 0 && product[j] < 0){
		ans += coupon[i] * product[j];
		i++;
		j++;
	}
	i = nc - 1;
	j = np - 1;
	while(i >= 0 && j >= 0 && coupon[i] > 0 && product[j] > 0){
		ans += coupon[i] * product[j];
		i--;
		j--;
	}
	printf("%d", ans);
	return 0;
}  
