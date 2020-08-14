#include<cstdio> 

struct Poly{
	int exp;//指数
	double cof;//系数
}poly[1010];

double ans[2010];

int main(){
	int k, m, cnt = 0;
	scanf("%d", &k);//第一个多项式中的非零系数的项数 
	for(int i = 0; i < k; i++){
		scanf("%d %lf", &poly[i].exp, &poly[i].cof);
	} 
	scanf("%d", &m);//第二个多项式中的非零项系数的项数 
	for(int i = 0; i < m; i++){
		int exp;
		double cof;
		scanf("%d %lf", &exp, &cof); 
		for(int j = 0; j < k; j++){//逐项和第一个多项式的每一项相乘 
			ans[exp + poly[j].exp] += cof * poly[j].cof; 
		} 
	}
	for(int i = 0; i <= 2000; i++){
		if(ans[i] != 0.0) cnt++;
	} 
	printf("%d",cnt);
	//我这边原本写了 报答案部分正确
	//不知道原因 
	/*for(int i = cnt; i >= 0; i--){
		if(ans[i]!=0.0){
			pritnf(" %d %.1f", i, ans[i]);
		}
	}
	*/ 
	for(int i = 2000; i >= 0; i--){
		if(ans[i] != 0.0){
			printf(" %d %.1f", i, ans[i]);
		}
	}
	return 0;
}
