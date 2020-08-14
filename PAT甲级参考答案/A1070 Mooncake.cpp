#include<cstdio>
#include<algorithm>
using namespace std;

struct Mooncake{
	double store;
	double price;
	double unitPrice;
}mooncake[1010];

bool cmp(Mooncake a, Mooncake b){
	return a.unitPrice > b.unitPrice;
} 

int main(){
	int n, demandStore;
	scanf("%d %d", &n, &demandStore);
	for(int i = 0; i < n; i++){
		scanf("%lf", &mooncake[i].store);
	}
	for(int i = 0; i < n; i++){
		scanf("%lf", &mooncake[i].price);
		mooncake[i].unitPrice = mooncake[i].price / mooncake[i].store;//计算单价 
	}
	sort(mooncake, mooncake + n, cmp);//按单价从高到低排序 
	double profit = 0;
	for(int i = 0; i < n; i++){
		if(mooncake[i].store < demandStore){
			profit += mooncake[i].price;
			demandStore -= mooncake[i].store;
		}else{
			profit += mooncake[i].unitPrice * demandStore;	
			demandStore = 0;
//			break;
//最好用break demandStore = 0 会执行多余的循环 浪费时间复杂度 
		}
	}
	printf("%.2f", profit);
	return 0;
} 
