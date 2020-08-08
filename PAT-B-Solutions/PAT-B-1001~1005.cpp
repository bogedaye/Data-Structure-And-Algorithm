/*
1001 害死人不偿命的(3n+1)猜想
卡拉兹(Callatz)猜想：

对任何一个正整数 n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把 (3n+1) 砍掉一半。这样一直反复砍下去，最后一定在某一步得到 n=1。卡拉兹在 1950 年的世界数学家大会上公布了这个猜想，传说当时耶鲁大学师生齐动员，拼命想证明这个貌似很傻很天真的命题，结果闹得学生们无心学业，一心只证 (3n+1)，以至于有人说这是一个阴谋，卡拉兹是在蓄意延缓美国数学界教学与科研的进展……

我们今天的题目不是证明卡拉兹猜想，而是对给定的任一不超过 1000 的正整数 n，简单地数一下，需要多少步（砍几下）才能得到 n=1？

输入格式：
每个测试输入包含 1 个测试用例，即给出正整数 n 的值。

输出格式：
输出从 n 计算到 1 需要的步数。

输入样例：
3

输出样例：
5

要点：模拟
*/

#include<cstdio>
int main(){
	int n,step=0;
	scanf("%d",&n);
	while(n!=1){
		if(n%2==0){
			n/=2;
			step++;
		}
		else {
			n = (3*n+1)/2;
			step++;
		}
		if(n==1)break;
	}
	printf("%d\n",step);
}

/*
1002 写出这个数
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^?100?? 。

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789

输出样例：
yi san wu

要点：
1.字符串->数字，数字->字符串，
2.大整数用字符串数组来存放，
3.数字如何和拼音进行对应？我用的是switch的蠢方法qwq
*/
#include<iostream>
using namespace std;
//把整型数据转换成拼音字母输出，用的switch 
void int_pinyin(int a){
	switch(a){
		case 0:cout<<"ling";break;
		case 1:cout<<"yi";break;
		case 2:cout<<"er";break;
		case 3:cout<<"san";break;
		case 4:cout<<"si";break;
		case 5:cout<<"wu";break;
		case 6:cout<<"liu";break;
		case 7:cout<<"qi";break;
		case 8:cout<<"ba";break;
		case 9:cout<<"jiu";break; 
	}
}

int main(){
	char a[101];
	cin>>a;
	int sum = 0,i = 0;
	
	//sum求和 
	while(a[i] != '\0'){
		sum+=a[i]-'0';
		i++;
	}
	int b[11],j = 0;	
	if(sum==0){
		int_pinyin(0);
	}	
	while(sum!=0){
		b[j] = sum%10;
		sum/=10;
		j++;
	}
	for(int i = j-1;i>0;i--){
		int_pinyin(b[i]);
		cout<<" ";
	}
	int_pinyin(b[0]);
	return 0;
}

/*
1003 我要通过！
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式：
每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

输出格式：
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：
YES
YES
YES
YES
NO
NO
NO
NO

要点：emmm这个题目首先是题意理解，我去，之前我一只没看懂这个题目讲的毛线，直到今天准备写题解才看懂…对，ac的代码是copy的别人的，真tm丢人！！！好的 吐槽完了，言归正传，我们开始讲题：首先要满足含有字符ＰＡＴ，并且ＰＴ只出现一次，并且Ｐ必须在Ｔ的前面．然后类似于ｘＰＡＴｘ这样的满足条件，其次就是如果 aPbTc 是正确的，那么 aPbATca 也是正确的．可以得出推导如下结论－－－＞＞
比如------>>
当PT之间只有一个A的时候： APATA —>> APAATAA , AAPATAA ----->> AAPAATAAAA ,…
即由PT之间只有一个A的状态能够推导出PT之间有两个A的状态
当PT之间有两个A的时候：APAATAA ---->> APAAATAAA, AAPAATAAAA ---->> AAPAAATAAAAAA
分析------->>相信大家都看出来了吧。字符串分为三段，P的左边，P、T之间，T的右边，分别统计A的个数，计为cnt1,cnt2,cnt3;满足条件cnt1*cnt2 = cnt3;感觉这题考的就是一个数学推理能力

*/
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int n,cout_p,cout_a,cout_t,pos_p,pos_t;
	char a[101];
	int b[100];
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a;
		cout_p = cout_a = cout_t = pos_p = pos_t = 0;
		int c = strlen(a);
		for(int j = 0;j<c;j++){
			if(a[j] == 'A'){
				cout_a++;
			}
			if(a[j] == 'P'){
				cout_p++;
				pos_p = j;  
			}
			if(a[j] == 'T'){
				cout_t++;
				pos_t = j;
			}
		} 
		if(cout_a+cout_p+cout_t!=strlen(a)||cout_p>1||cout_t>1||pos_p+1>=pos_t
		||pos_p*(pos_t-pos_p-1)!=strlen(a)-pos_t-1)
			b[i] = 0;
		else 
			b[i] = 1;
	}
	for(int i = 0;i<n;i++){
		if(b[i]==0)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}

/*
1004 成绩排名
读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：
每个测试输入包含 1 个测试用例，格式为

第 1 行：正整数 n
第 2 行：第 1 个学生的姓名 学号 成绩
第 3 行：第 2 个学生的姓名 学号 成绩
… … …
第 n+1 行：第 n 个学生的姓名 学号 成绩

其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：
对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出样例：
Mike CS991301
Joe Math990112

要点：struct结构体
*/ 
//经典的结构体数组题目
//可以在这个上面衍生出很多变体 
#include<stdio.h>
struct student_{
	char name[11];
	char number[11];
	int score;
};

int main(){
	int n,i,max,min;
	scanf("%d",&n);
	struct student_ student[n];
	for(int i = 0;i<n;i++){
		scanf("%s %s %d",&student[i].name,&student[i].number,&student[i].score); 
	}
	max = min = 0;
	for(int i = 0;i<n;i++){
		if(student[max].score<student[i].score)max = i;
		if(student[min].score>student[i].score)min = i;
	} 
	printf("%s %s\n",student[max].name,student[max].number);
	printf("%s %s\n",student[min].name,student[min].number);
	return 0;
}

/*
1005 继续(3n+1)猜想
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对 n=3 进行验证的时候，我们需要计算 3、5、8、4、2、1，则当我们对 n=5、8、4、2 进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这 4 个数已经在验证3的时候遇到过了，我们称 5、8、4、2 是被 3“覆盖”的数。我们称一个数列中的某个数 n 为“关键数”，如果 n 不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

输入格式：
每个测试输入包含 1 个测试用例，第 1 行给出一个正整数 K (<100)，第 2 行给出 K 个互不相同的待验证的正整数 n (1<n≤100)的值，数字间用空格隔开。

输出格式：
每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用 1 个空格隔开，但一行中最后一个数字后没有空格。

输入样例：
6
3 5 6 7 8 11

输出样例：
7 6

要点：
1.数是否被覆盖用flag[10001]来表示，flag[]=1设定被覆盖了，而flag[]=0表示没有被覆盖，
2.num[101]用来存放每次输入的t，因为t进入循环之后，值会有变化，因为后期要判断flag[t]，t有变化，则判断flag[num[i]]?0
3.输出格式是数字间用一个空格隔开，但一行中最后一个数字没有空格：for(int i = 0;i<number;i++){cout<<ans[i]；if(i！=number-1)cout<<" ";}，这个输出格式需要熟练掌握，算法题很多都设置这种输出要求，可以先背上，而后在写的过程中逐渐理解
*/ 
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int flag[100001] = {0};
	int num[101] = {0};
	int ans[101] = {0};
	int n,t,number = 0;
	cin>>n;
	for (int i = 0; i<n; i++) {
        cin>>t;
        num[i] = t;
        while (t!= 1) {
            if (t%2!=0) t =3*t+1;
            t = t/2;
            flag[t] = 1;
        }
    }
	for(int i = 0;i<n;i++){
		if(flag[num[i]]==0)ans[number++] = num[i];
	}
	sort(ans,ans+number,cmp);
	for(int i = 0;i<number;i++){
		cout<<ans[i];
		if(i!=number-1)cout<<" ";
	}
	return 0;
}

