#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 110;
int origin[N], tempOri[N], target[N];//原始数组 原始数组备份 目标数组 
int n;//元素个数 

bool isSame(int A[], int B[]){
	for(int i = 0; i < n; i++){
		if(A[i] != B[i]){
			return false;
		}
	} 
	return true;
}

bool insertSort(){//插入排序 
	bool flag = false;//记录是否存在数组中间步骤与changed数组相同 
	for(int i = 1; i < n; i++){//进行 n - 1趟排序 
		if(i != 1 && isSame(tempOri, target)){
			flag = true;
		} 
		//以下为插入部分
		int temp = tempOri[i], j = i;
		while(j > 0 && tempOri[j - 1] > temp){
			tempOri[j] = tempOri[j - 1];
			j--;
		} 
		tempOri[j] = temp;
		if(flag == true){
			return true;//如果flag为true 则说明已经到达目标数组 返回true 
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
	bool flag = false;//记录是否存在数组中间步骤与changed数组相同
	//以下为归并排序部分
	for(int step = 2; step / 2 <= n; step *= 2){
		if(step != 2 && isSame(tempOri, target)){
			flag = true;//中间步骤与目标相同 且不是初始序列 
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
		scanf("%d", &origin[i]);//输入起始数组
		tempOri[i] = origin[i];//tempOri数组为备份 排序过程在tempOri上进行 
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &target[i]);//目标数组 
	} 
	if(insertSort()){//如果在插入排序中找到目标数组 
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
