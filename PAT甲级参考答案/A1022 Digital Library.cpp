#include<map>
#include<cstdio>
#include<cstring>
#include<set> 
#include<string.h>
#include<iostream>
using namespace std;

map<string, set<int>> mapTitle, mapAuthor, mapKeyword, mapPublisher, mapYear;

void query(string& str, map<string, set<int>>& mp){
	if(mp.find(str) != mp.end()){//�ҵ�str 
		for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){
			printf("%07d\n",*it);
		}
	}else if(mp.find(str) == mp.end()){//�Ҳ���str 
		printf("Not Found\n");
	}
}

int main(){
	int n, m, id, type;
	string title, author, keyword, publisher, year;
	scanf("%d",&n);//�����Ŀ 
	for(int i = 0; i < n; i++){
		scanf("%d",&id);//id
		char c = getchar();//���յ�id����Ļ���
		getline(cin, title);//��������title
		mapTitle[title].insert(id);//��id���뵽title��Ӧ�ļ����� 
		getline(cin, author);//��������author
		mapAuthor[author].insert(id);//��id���뵽author��Ӧ�ļ����� 
		while(cin >> keyword){//ÿ�ζ��뵥���ؼ���keyword 
			mapKeyword[keyword].insert(id);//��id���뵽keyword��Ӧ�ļ�����
			c = getchar();//���չؼ���keyword֮����ַ�
			if(c == '\n')break;//����ǻ��� ˵���ؼ���������� 
		} 
		getline(cin, publisher);
		mapPublisher[publisher].insert(id);
		getline(cin, year);
		mapYear[year].insert(id);
	}
	//��ѯ
	string temp;
	scanf("%d",&m);//��ѯ���� 
	for(int i = 0; i < m; i++){
		scanf("%d: ",&type);//��ѯ���� 
		getline(cin, temp);//����ѯ���ַ��� 
		cout << type << ": " << temp << endl;//������ͺ͸��ַ���
		if(type == 1) query(temp, mapTitle);
		else if(type == 2) query(temp, mapAuthor);
		else if(type == 3) query(temp, mapKeyword);
		else if(type == 4) query(temp, mapPublisher);
//		else if(type == 5)query(temp, mapYear); 
		else query(temp, mapYear);
	}
	return 0;
}
