#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

/* ZAR ATMA OYUNU (CRAPS)

1)Ýki zar atýlýr
2)Gelen zarlar toplanýr.
3)Ýlk atýþta sonuç 7 veya 11 ise oyuncu kazanýr.
4)Ýlk atýþta 2, 3 veya 12 gelirse oyuncu kaybeder.
5)Bu durumlar oluþmazsa ilk atýþta gelen sayý oyuncunun puaný oluyor. Oyuncu bu durumdan sonra kazanmak için ilk attýðý zarý atmalýdýr.
NOT: Ýlk zardan sonra 6 defa daha atacak puanýný tutturamazsa kaybeder.

*/



int ilkatis_kazanma(int,int);
int ilkatis_kaybetme(int,int);

typedef struct {
	
	int puan;
	int zar1,zar2;
	char isim[50];
	char choose;
	
}Oyuncu;

Oyuncu Oyuncu1,Oyuncu2;



int main (void)
{
	setlocale(LC_ALL,"Turkish");
	srand(time(NULL));		

	printf("Kullanýcýlarýn isimlerini sýrasýyla giriniz(Oyuncu1,Oyuncu2):"); 
	fgets(Oyuncu1.isim, sizeof(Oyuncu1.isim), stdin);                         // Önce girileni alýr. Sonra girileni 50 karakteri aþmayacak þekilde okur.
	Oyuncu1.isim[strcspn(Oyuncu1.isim, "\n")] = '\0';
	
	fgets(Oyuncu2.isim, sizeof(Oyuncu2.isim), stdin);  
	Oyuncu2.isim[strcspn(Oyuncu2.isim, "\n")] = '\0';
	
	printf("%s zar atsýn mý(Evet için: E): ",Oyuncu1.isim);
	scanf("%c",&Oyuncu1.choose);
	
	if(Oyuncu1.choose != 'E')
	{
		printf("%s zar atýþý yapmadý.\n",Oyuncu1.isim);
		return -1;
	}	
	
	else
	{
		printf("%s zar atýyor... \n",Oyuncu1.isim); sleep(2);
		
		Oyuncu1.zar1 = rand()%6 + 1;
		Oyuncu1.zar2 = rand()%6 + 1;
		
		printf("%s ZAR1: %d ZAR2: %d\n",Oyuncu1.isim,Oyuncu1.zar1,Oyuncu1.zar2);
		
		Oyuncu1.puan = Oyuncu1.zar2 + Oyuncu1.zar1;
	}
	
	
	printf("%s zar atsýn mý(Evet için: E): ",Oyuncu2.isim);
	getchar();
	scanf("%c",&Oyuncu2.choose);
	
	if(Oyuncu2.choose != 'E')
	{
		printf("%s zar atýþý yapmadý.\n",Oyuncu2.isim);
		return -1;
	}	
	
	else
	{
		printf("%s zar atýyor... \n",Oyuncu2.isim); sleep(2);
		
		Oyuncu2.zar1 = rand()%6 + 1;
		Oyuncu2.zar2 = rand()%6 + 1;
		
		printf("%s ZAR1: %d ZAR2: %d\n",Oyuncu2.isim,Oyuncu2.zar1,Oyuncu2.zar2);
		
		Oyuncu2.puan = Oyuncu2.zar2 + Oyuncu2.zar1;
	}
	
	int durum = ilkatis_kazanma(Oyuncu1.puan,Oyuncu2.puan);

	if(durum == 0)
		return -1;
	
	durum = ilkatis_kaybetme(Oyuncu1.puan,Oyuncu2.puan);
	
	if(durum == 0)
		return -1;	

	sleep(2);
	
	printf("Ýlk atýþlarda kaybeden veya kazanan olmadý 2.tur baþlýyor...\n");
	
	sleep(2);
	
	int hak = 5 ; 
	int o1,o2;
	
	while(hak >= 0)
	{
		
		Oyuncu1.zar1 = rand()%6 + 1;
		Oyuncu1.zar2 = rand()%6 + 1;	
		
		int gecici_puan = Oyuncu1.zar1 + Oyuncu1.zar2 ;
		
		if(gecici_puan == Oyuncu1.puan)
			o1 = hak;
		
		Oyuncu2.zar1 = rand()%6 + 1;
		Oyuncu2.zar2 = rand()%6 + 1;	
		
		gecici_puan = Oyuncu2.zar1 + Oyuncu2.zar2 ;
		
		if(gecici_puan == Oyuncu2.puan)
			o2 = hak;
		
		hak--;
	}
	
	if( o2 < o1 )
	{
		printf("%s ilk turda attýðý zarý tekrar atarak %d. atýþýnda kazandý\n",Oyuncu2.isim,o2 + 1);
	}
	
	else if( o2 > o1)
	{
		printf("%s ilk turda attýðý zarý tekrar atarak %d. atýþýnda kazandý\n",Oyuncu1.isim,o1 + 1);
	}
	
	else 
		printf("Ýki oyuncu da ilk turda attýðý zarlarý ayný anda attýðý için berabere\n");
	
	return 0;
}

int ilkatis_kazanma(int puan1,int puan2)
{
	
	int oyuncu1,oyuncu2;
	
	oyuncu1 = (puan1 == 11 || puan1 == 7) ? 1 : 0;
	oyuncu2 = (puan2 == 11 || puan2 == 7) ? 1 : 0;
	
	
	if(oyuncu1 > oyuncu2)
	{
		printf("%s 11 veya 7 atarak kazandý\n",Oyuncu1.isim);
		return 0;
	}
				
		
	else if(oyuncu2 > oyuncu1)
	{
		printf("%s 11 veya 7 atarak kazandý.\n",Oyuncu2.isim);
		return 0;
	}
			
	
	else if(oyuncu1 == 1 && oyuncu2 == 1)
	{
		printf("Her iki oyuncu da 11 veya 7 atarak kazandý\n");
		return 0;	
	}	
		
	return 1;
}

int ilkatis_kaybetme(int puan1, int puan2)
{
	int oyuncu1,oyuncu2;
	
	oyuncu1 = (puan1 == 2 || puan1 == 3 || puan1 == 12) ? 0 : 1;
	oyuncu2 = (puan2 == 2 || puan2 == 3 || puan2 == 12) ? 0 : 1;
	
	if(oyuncu1 > oyuncu2)
	{
		printf("%s kazandý çünkü %s 2, 3 veya 12 atarak kaybetti\n",Oyuncu1.isim,Oyuncu2.isim);
		return 0;
	}
				
		
	else if(oyuncu2 > oyuncu1)
	{
		printf("%s kazandý çünkü %s 2, 3 veya 12 atarak kaybetti.\n",Oyuncu2.isim,Oyuncu1.isim);
		return 0;
	}
			
	else if(oyuncu1 == 0 && oyuncu2 == 0)
	{
		printf("Her iki oyuncu da 2, 3 veya 12 atarak kaybetti\n");
		return 0;	
	}
	
	return 1;
}
