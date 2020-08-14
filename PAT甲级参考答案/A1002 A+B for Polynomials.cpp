#include<iostream>
using namespace std;
int main(){
	float c[1001] = {0};//c[0],...,c[1000]={0,...,0}
	int m , n , t;
	float num;
	scanf("%d",&m);//2
	for(int i = 0;i<m;i++){
		scanf("%d%f",&t,&num);//1 2.4 0 3.2
		c[t] += num;//c[1]=2.4;c[0]=3.2
	}
	scanf("%d",&n);//2
	for(int i = 0;i<n;i++){
		scanf("%d%f",&t,&num);//2 1.5 1 0.5
		c[t] += num;//c[2]=1.5;c[1]=2.9
	}
	int cnt = 0;
	for(int i = 0;i<1001;i++){
		if(c[i]!=0)cnt++;//
	}
	printf("%d",cnt);//3
	for(int i =1000;i>=0;i--){
		if(c[i]!=0.0)
			printf(" %d %.1f",i,c[i]);
			//¿Õ¸ñi¿Õ¸ñc[i] i->exponent;c[i]->coefficient 
	}
	return 0;
} 
