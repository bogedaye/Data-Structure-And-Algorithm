#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 110;
int origin[N], tempOri[N], target[N];//ԭʼ���� ԭʼ���鱸�� Ŀ������ 
int n;//Ԫ�ظ��� 

bool isSame(int A[], int B[]){
	for(int i = 0; i < n; i++){
		if(A[i] != B[i]){
			return false;
		}
	} 
	return true;
}

bool insertSort(){//�������� 
	bool flag = false;//��¼�Ƿ���������м䲽����changed������ͬ 
	for(int i = 1; i < n; i++){//���� n - 1������ 
		if(i != 1 && isSame(tempOri, target)){
			flag = true;
		} 
		//����Ϊ���벿��
		int temp = tempOri[i], j = i;
		while(j > 0 && tempOri[j - 1] > temp){
			tempOri[j] = tempOri[j - 1];
			j--;
		} 
		tempOri[j] = temp;
		if(flag == true){
			return true;//���flagΪtrue ��˵���Ѿ�����Ŀ������ ����true 
		} 
	}
	return false; 
}

void showArray(int A[]){
	for(int i = 0; i < n; i++){
		printf("%d", A[i]);
		if(i < n - 1)printf(" ");
	}
	printf("\n");
}

void mergeSort(){
	bool flag = false;//��¼�Ƿ���������м䲽����changed������ͬ
	//����Ϊ�鲢���򲿷�
	for(int step = 2; step / 2 <= n; step *= 2){
		if(step != 2 && isSame(tempOri, target)){
			flag = true;//�м䲽����Ŀ����ͬ �Ҳ��ǳ�ʼ���� 
		}
		for(int i = 0; i < n; i += step){
			sort(tempOri + i, tempOri + min(i + step, n));
		} 
		if(flag == true){
			showArray(tempOri);
			return; 
		}
	} 
}



int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &origin[i]);//������ʼ����
		tempOri[i] = origin[i];//tempOri����Ϊ���� ���������tempOri�Ͻ��� 
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &target[i]);//Ŀ������ 
	} 
	if(insertSort()){//����ڲ����������ҵ�Ŀ������ 
		printf("Insertion Sort\n"); 
		showArray(tempOri);
	}else{
		printf("Merge Sort\n");
		for(int i = 0; i < n; i++){
			tempOri[i] = origin[i];
		}
		mergeSort();
	}
	return 0;
}
