#include<cstdio> 

struct Poly{
	int exp;//ָ��
	double cof;//ϵ��
}poly[1010];

double ans[2010];

int main(){
	int k, m, cnt = 0;
	scanf("%d", &k);//��һ������ʽ�еķ���ϵ�������� 
	for(int i = 0; i < k; i++){
		scanf("%d %lf", &poly[i].exp, &poly[i].cof);
	} 
	scanf("%d", &m);//�ڶ�������ʽ�еķ�����ϵ�������� 
	for(int i = 0; i < m; i++){
		int exp;
		double cof;
		scanf("%d %lf", &exp, &cof); 
		for(int j = 0; j < k; j++){//����͵�һ������ʽ��ÿһ����� 
			ans[exp + poly[j].exp] += cof * poly[j].cof; 
		} 
	}
	for(int i = 0; i <= 2000; i++){
		if(ans[i] != 0.0) cnt++;
	} 
	printf("%d",cnt);
	//�����ԭ��д�� ���𰸲�����ȷ
	//��֪��ԭ�� 
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
