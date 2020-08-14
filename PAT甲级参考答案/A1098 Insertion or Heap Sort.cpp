#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 110;
int origin[N], tempOri[N], changed[N];
int n;

bool isSame(int A[], int B[]){
	for(int i = 1; i <= n; i++){
		if(A[i] != B[i]) return false;
	}
	return true;
}

//�������� 
bool insertSort(){
	bool flag = false;//��¼�Ƿ���������м䲽����changed������ͬ
	for(int i = 2; i <= n; i++){//����n-1������ 
		if(i != 2 && isSame(tempOri, changed)){
			flag = true;//�м䲽����Ŀ����ͬ �Ҳ��ǳ�ʼ���� 
		} 
		//���벿��ֱ����sort���
		sort(tempOri, tempOri + i + 1);
		if(flag == true){
			return true;//���flagΪtrue ��˵���Ѿ�����Ŀ������ ����true 
		}
	} 
	return false;//�޷��ﵽĿ������ ����false 
}

void showArray(int A[]){
	for(int i = 1; i <= n; i++){
		printf("%d", A[i]);
		if(i < n) printf(" ");
	}
	printf("\n");
}

//��heap������[low, high]��Χ���е���
//����lowΪ����������������±� highһ��Ϊ�����һ��Ԫ�ص������±�
void downAdjust(int low, int high){
	int i = low , j = 2 * i;
	while(j <= high){
		if(j + 1 <= high && tempOri[j + 1] > tempOri[j]){
			j = j + 1;
		}
		if(tempOri[j] > tempOri[i]){
			swap(tempOri[j], tempOri[i]);
			i = j;//������һ�� 
			j = 2 * i;
		} else{
			break;
		}
	}
} 

//������ 
void heapSort(){
	bool flag = false;
	for(int i = n / 2; i >= 1; i--){
		downAdjust(i, n);//���� 
	}
	for(int i = n; i > 1; i--){
		if(i != n && isSame(tempOri, changed)){
			flag = true;//�м䲽����Ŀ����ͬ �Ҳ��ǳ�ʼ���� 
		}
		swap(tempOri[i], tempOri[1]);//����heap[i]��Ѷ�
		downAdjust(1, i - 1);
		if(flag == true){
			showArray(tempOri);
			return;
		} 
	} 
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &origin[i]);//������ʼ���� 
		tempOri[i] = origin[i];//tempOriΪ���鱸�� ������tempOri�Ͻ��� 
	}	
	for(int i = 1; i <= n; i++){
		scanf("%d", &changed[i]);
	}
	if(insertSort()){
		printf("Insertion Sort\n");
		showArray(tempOri);
	} else{
		printf("Heap Sort\n");
		for(int i = 1; i <= n; i++){
			tempOri[i] = origin[i];
		}	
		heapSort();
	}
	return 0;
} 
