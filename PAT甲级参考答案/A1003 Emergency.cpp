#include<iostream>
#include<cstring>
using namespace std;

#define INF 99999
#define Ncity 501
#define Nroad 10000

int team[Ncity];
int road[Ncity][Ncity];
int dst[Nroad];
int book[Ncity];
int maxteam[Ncity];
int way[Ncity];

int main(){
	int N,M,C1,C2;
	cin>>N>>M>>C1>>C2;
	int i,j,k,u,min;
	
	//≥ı ºªØ
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			road[i][j] = INF;
		}
	} 
	
	memset(book,0,sizeof(book));
	for(int i = 0;i<N;i++){
		cin>>team[i];
	}
	for(int i = 1;i<=M;i++){
		cin>>j>>k;
		cin>>road[j][k];
		road[k][j] = road[j][k];
	}
	for(int i = 0;i<N;i++){
		dst[i] = road[C1][i];
		maxteam[i] = team[i];
		way[i] = 1;
		if(dst[i]!=INF&&i!=C1){
			maxteam[i] += team[C1];
		}
	}
	book[C1] = 1;
	for(i = 1; i < N; i++){
		min = INF;
		for(j = 0; j < N; j++){
			if(book[j] == 0 && dst[j] < min){
				min = dst[j];
				u = j;
			}
		}
		book[u] = 1;
		for(k = 0; k < N; k++){
		   if(road[u][k]<INF && book[k]==0){
			   if(dst[k] > dst[u]+road[u][k]){
				    dst[k] = dst[u] + road[u][k];
					maxteam[k] = maxteam[u] + team[k];
					way[k] = way[u];
			   }else if(dst[k] == dst[u]+road[u][k]){
			   		way[k] += way[u];
			   		if(maxteam[k] < maxteam[u]+team[k]){
			   			maxteam[k]=	maxteam[u]+team[k];			
					}
			   }
		   }
              }
	}	
	cout<<way[C2]<<" "<<maxteam[C2];
	return 0;
} 
