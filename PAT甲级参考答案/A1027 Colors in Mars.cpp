#include<cstdio>

char mp[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
				'A', 'B', 'C'};

int main(){
	int red, green, blue;
	scanf("%d %d %d", &red, &green, &blue);
	printf("#");
	printf("%c%c", mp[red / 13], mp[red % 13]);
	printf("%c%c", mp[green / 13], mp[green % 13]);
	printf("%c%c", mp[blue / 13], mp[blue % 13]);
	return 0;
}
