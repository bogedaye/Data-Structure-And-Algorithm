#include<cstdio>

int main(){
	int Galleon1, Sickle1, Knut1;
	int Galleon2, Sickle2, Knut2;
	int ansGalleon, ansSickle, ansKnut;
	scanf("%d.%d.%d %d.%d.%d", &Galleon1, &Sickle1, &Knut1,
		&Galleon2, &Sickle2, &Knut2);
	int temp1, temp2;
	temp1 = (Knut1 + Knut2) / 29;
	temp2 = (temp1 + Sickle1 + Sickle2) / 17; 
	printf("%d.%d.%d", Galleon1 + Galleon2 + temp2  
	,(temp1 + Sickle1 + Sickle2) % 17
	,(Knut1 + Knut2) % 29);
}
