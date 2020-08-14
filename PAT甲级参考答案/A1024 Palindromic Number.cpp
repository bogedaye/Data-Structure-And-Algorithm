#include<cstdio>
#include<algorithm>
#include<string.h> 
using namespace std;

struct bign{
	int d[1000];
	int len = 0;
//	int len;
	bign(){
		memset(d, 0, sizeof(d));
//		len = 0;
	}
};

bign change(char str[]){
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++){
		a.d[i] = str[a.len - 1 - i] - '0';
//		a.len++;
	}
	return a;
} 

bool judge(bign a){
	for(int i = 0; i < a.len / 2; i++){
		if(a.d[i] != a.d[a.len - 1 - i]){
			return false;
		}
	}
	return true;
}

bign add(bign a, bign b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++){
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0){
		c.d[c.len++]= carry;
	}
	return c;
}

void print(bign a){
	for(int i = a.len - 1; i >= 0; i--){
		printf("%d", a.d[i]);
	}
}

int main(){
	char str[1000];
	int N, step = 0;
	scanf("%s %d", str, &N);
	bign a = change(str);
	while(step < N && judge(a) == false){
		bign b = a;
		reverse(b.d, b.d + b.len);
		a = add(a, b);
		step++;
	}
	print(a);
	printf("\n%d", step); 
	return 0;
} 
