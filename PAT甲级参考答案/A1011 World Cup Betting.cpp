#include<cstdio>
using namespace std;
 
char mp[3] = {'W', 'T', 'L'};

int main(){
	double profit = 1.0, tmp, value;
	int index;//��¼ÿ��������ֵ��±� 
	for(int i = 0; i < 3; i++){
		tmp = 0.0;//Ѱ�Ҹ�������ֵ����tmp 
		for(int j = 0; j < 3; j++){
			scanf("%lf", &value);
			if(value > tmp){
				tmp = value;
				index = j;
			} 
		}
		profit *= tmp; 
		printf("%c ",mp[index]);
	}
	printf("%.2f", (profit * 0.65 - 1) * 2);//���������� 
	return 0;
} 
