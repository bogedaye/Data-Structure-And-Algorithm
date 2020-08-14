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

//插入排序 
bool insertSort(){
	bool flag = false;//记录是否存在数组中间步骤与changed数组相同
	for(int i = 2; i <= n; i++){//进行n-1趟排序 
		if(i != 2 && isSame(tempOri, changed)){
			flag = true;//中间步骤与目标相同 且不是初始序列 
		} 
		//插入部分直接用sort替代
		sort(tempOri, tempOri + i + 1);
		if(flag == true){
			return true;//如果flag为true 则说明已经到达目标数组 返回true 
		}
	} 
	return false;//无法达到目标数组 返回false 
}

void showArray(int A[]){
	for(int i = 1; i <= n; i++){
		printf("%d", A[i]);
		if(i < n) printf(" ");
	}
	printf("\n");
}

//对heap数组在[low, high]范围进行调整
//其中low为欲调整结点的数组的下标 high一般为堆最后一个元素的数组下标
void downAdjust(int low, int high){
	int i = low , j = 2 * i;
	while(j <= high){
		if(j + 1 <= high && tempOri[j + 1] > tempOri[j]){
			j = j + 1;
		}
		if(tempOri[j] > tempOri[i]){
			swap(tempOri[j], tempOri[i]);
			i = j;//进入下一层 
			j = 2 * i;
		} else{
			break;
		}
	}
} 

//堆排序 
void heapSort(){
	bool flag = false;
	for(int i = n / 2; i >= 1; i--){
		downAdjust(i, n);//建堆 
	}
	for(int i = n; i > 1; i--){
		if(i != n && isSame(tempOri, changed)){
			flag = true;//中间步骤与目标相同 且不是初始序列 
		}
		swap(tempOri[i], tempOri[1]);//交换heap[i]与堆顶
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
		scanf("%d", &origin[i]);//输入起始数组 
		tempOri[i] = origin[i];//tempOri为数组备份 排序在tempOri上进行 
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
