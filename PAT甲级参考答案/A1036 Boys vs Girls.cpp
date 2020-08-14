#include<cstdio>

struct Student{
	char name[20];
	char ID[20];
	int grade;
}maleStudent, femaleStudent, temp;

void init(){
	maleStudent.grade = 101;
	femaleStudent.grade = -1;
}

int main(){
	init();
	int N;
	char gender;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s %c %s %d", temp.name, &gender, temp.ID, &temp.grade);
//		scanf("%s%c%s%d", temp.name, &gender, temp.ID, &temp.grade); 
		//输入不按格式输入会WA 
		if(gender == 'M' && temp.grade < maleStudent.grade){
			maleStudent = temp;
		}else if(gender == 'F' && temp.grade > femaleStudent.grade){
			femaleStudent = temp;
		}
	}
	if(femaleStudent.grade == -1){
		printf("Absent\n");
	}else{
		printf("%s %s\n", femaleStudent.name, femaleStudent.ID);
	}
	if(maleStudent.grade == 101){
		printf("Absent\n");
	}else{
		printf("%s %s\n", maleStudent.name, maleStudent.ID);
	}
	if(femaleStudent.grade == -1 || maleStudent.grade == 101){
		printf("NA");
	}else{
		printf("%d", femaleStudent.grade - maleStudent.grade);
	}
	return 0;
} 
