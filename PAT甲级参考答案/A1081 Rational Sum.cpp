#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}

struct Fraction{
	ll up, down; 
};

//？ 
Fraction reducation(Fraction result){
	if(result.down < 0){//分母为负数 令分子和分母都变为相反数 
		result.up = - result.up;
		result.down = - result.down;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction add(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down + f1.down * f2.up;
	result.down = f1.down * f2.down;
	return reducation(result); 
} 

void showResult(Fraction r){
	reducation(r);//输出分数
	if(r.down == 1) printf("%lld\n", r.up);
	else if(abs(r.up) > abs(r.down)){
		printf("%lld %lld/%lld\n", r.up / r.down, abs(r.up) % r.down, r.down);
	}else{
		printf("%lld/%lld\n", r.up, r.down);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	Fraction sum, temp;
	sum.up = 0, sum.down = 1;
	for(int i = 0; i < n; i++){
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}
	showResult(sum); 
	return 0;
}
