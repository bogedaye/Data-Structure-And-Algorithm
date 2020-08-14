#include<map>
#include<cstdio>
#include<cstring>
#include<set> 
#include<string.h>
#include<iostream>
using namespace std;

map<string, set<int>> mapTitle, mapAuthor, mapKeyword, mapPublisher, mapYear;

void query(string& str, map<string, set<int>>& mp){
	if(mp.find(str) != mp.end()){//找到str 
		for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){
			printf("%07d\n",*it);
		}
	}else if(mp.find(str) == mp.end()){//找不到str 
		printf("Not Found\n");
	}
}

int main(){
	int n, m, id, type;
	string title, author, keyword, publisher, year;
	scanf("%d",&n);//书的数目 
	for(int i = 0; i < n; i++){
		scanf("%d",&id);//id
		char c = getchar();//接收掉id后面的换行
		getline(cin, title);//读入书名title
		mapTitle[title].insert(id);//将id加入到title对应的集合中 
		getline(cin, author);//读入作者author
		mapAuthor[author].insert(id);//将id加入到author对应的集合中 
		while(cin >> keyword){//每次读入单个关键词keyword 
			mapKeyword[keyword].insert(id);//将id加入到keyword对应的集合中
			c = getchar();//接收关键词keyword之后的字符
			if(c == '\n')break;//如果是换行 说明关键词输入结束 
		} 
		getline(cin, publisher);
		mapPublisher[publisher].insert(id);
		getline(cin, year);
		mapYear[year].insert(id);
	}
	//查询
	string temp;
	scanf("%d",&m);//查询次数 
	for(int i = 0; i < m; i++){
		scanf("%d: ",&type);//查询类型 
		getline(cin, temp);//欲查询的字符串 
		cout << type << ": " << temp << endl;//输出类型和该字符串
		if(type == 1) query(temp, mapTitle);
		else if(type == 2) query(temp, mapAuthor);
		else if(type == 3) query(temp, mapKeyword);
		else if(type == 4) query(temp, mapPublisher);
//		else if(type == 5)query(temp, mapYear); 
		else query(temp, mapYear);
	}
	return 0;
}
