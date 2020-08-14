#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

struct station{
	double price, dis;//�۸������ľ��� 
}st[maxn];

bool cmp(station a, station b){
	return a.dis < b.dis;//�������С�������� 
}

int main(){
	int n;
	double Cmax, D, Davg;
	scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &n);
	for(int i = 0; i < n; i++){
		scanf("%lf %lf", &st[i].price, &st[i].dis);
	}
	st[n].price = 0;//�������������յ� �۸�Ϊ0
	st[n].dis = D;//�յ����ΪD
	sort(st, st + n, cmp);//�����м���վ�������С��������
	if(st[0].dis != 0){//��������ĵ�һ������վ���벻��0 ˵���޷�ǰ��
		printf("The maximum travel distance = 0.00\n"); 
	}else{
		int now = 0;//��ǰ�����ļ���վ���
		//�ܻ��ѡ���ǰ������������ʻ����
		double ans = 0, nowTank = 0, MAX = Cmax * Davg;
		while(now < n){//ÿ��ѭ����ѡ����һ����Ҫ����ļ���վ 
		//ѡ���ӵ�ǰ����վ�����ܵ��ﷶΧ�ڵĵ�һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ
		//���û�е��ڵ�ǰ�ͼ۵ļ���վ�� ��ѡ��۸���͵��Ǹ�
			int k = -1;//����ͼ۵ļ���վ��� 
			double priceMin = INF;//����ͼ�
			for(int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; i++){
				if(st[i].price < priceMin){//����ͼ۱ȵ�ǰ����ͼ۵� 
					priceMin = st[i].price;//��������ͼ�
					k = i;
					//����ҵ���һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ ֱ���ж�ѭ��
					if(priceMin < st[now].price){
						break;
					} 
				}
			} 
			if(k == -1) break;//����״̬���޷��ҵ�����վ �˳�ѭ��������
			//����Ϊ���ҵ��ɵ���ļ���վk ����ת�ƻ���
			//needΪ��now��k��Ҫ������
			double need = (st[k].dis - st[now].dis) / Davg;
			if(priceMin < st[now].price){//�������վk���ͼ۵��ڵ�ǰ�ͼ� 
				//ֻ���㹻�������վk����
				if(nowTanK < need){//�����ǰ��������need 
					ans += (need - nowTank) * st[now].price;//����need
					nowTank = 0;//�������վk������������Ϊ0 
				}else{//�����ǰ��������need 
					nowTank -= need;//ֱ�ӵ������վk 
				}
			} else{//�������վ���ͼ۸��ڵ�ǰ�ͼ� 
				ans += (Cmax - nowTank) * st[now].price;//���������
				//�������վk��������ΪCmax - need
				nowTank = Cmax - need; 
			}
			now = k;//������վk ������һ��ѭ�� 
		} 
		if(now == n){//�ܵ����յ� 
			printf("%.2f\n", ans); 
		} else{
			printf("The maximum travel distance = %.2f\n", st[now].dis + MAX);
		}
	}
	return 0;
} 
